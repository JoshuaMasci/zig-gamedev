# zimgui v0.2.0 - dear imgui bindings

Easy to use, hand-crafted API with default arguments, named parameters and Zig style text formatting. [Here](https://github.com/michal-z/zig-gamedev/tree/main/samples/minimal_zgpu_zimgui) is a simple sample application, and [here](https://github.com/michal-z/zig-gamedev/tree/main/samples/gui_test_wgpu) is a full one.

## Features

* Most public dear imgui API exposed
* All memory allocations go through user provided Zig allocator
* [DrawList API](#drawlist-api) for vector graphics, text rendering and custom widgets
* [Plot API](#plot-api) for advanced data visualizations
* [Test engine API](#test-engine-api) for automatic testing

## Versions

* [ImGui](https://github.com/ocornut/imgui/tree/v1.90.4-docking) `1.90.4-docking`
* [ImGui test engine](https://github.com/ocornut/imgui_test_engine/tree/v1.90.4)  `1.90.4`
* [ImPlot](https://github.com/epezent/implot) `O.17`

## Getting started

Copy `zimgui` to a subdirectory in your project and add the following to your `build.zig.zon` .dependencies:
```zig
    .zimgui = .{ .path = "libs/zimgui" },
```

To get glfw/wgpu rendering backend working also copy `zglfw`, `system-sdk`, `zgpu` and `zpool` folders and add the depenency paths (see [zgpu](https://github.com/zig-gamedev/zig-gamedev/tree/main/libs/zgpu) for the details).

Then in your `build.zig` add:
```zig

pub fn build(b: *std.Build) void {
    const exe = b.addExecutable(.{ ... });

    const zimgui = b.dependency("zimgui", .{
        .shared = false,
        .with_implot = true,
    });
    exe.root_module.addImport("zimgui", zimgui.module("root"));
    exe.linkLibrary(zimgui.artifact("imgui"));
    
    { // Needed for glfw/wgpu rendering backend
        const zglfw = b.dependency("zglfw", .{});
        exe.root_module.addImport("zglfw", zglfw.module("root"));
        exe.linkLibrary(zglfw.artifact("glfw"));

        const zpool = b.dependency("zpool", .{});
        exe.root_module.addImport("zpool", zpool.module("root"));

        const zgpu = b.dependency("zgpu", .{});
        exe.root_module.addImport("zgpu", zgpu.module("root"));
        exe.linkLibrary(zgpu.artifact("zdawn"));
    }
}
```

Now in your code you may import and use `zimgui`:

```zig
const zimgui = @import("zimgui");

zimgui.init(allocator);

_ = zimgui.io.addFontFromFile(content_dir ++ "Roboto-Medium.ttf", 16.0);

zimgui.backend.init(
    window,
    demo.gctx.device,
    @enumToInt(swapchain_format),
    @enumToInt(depth_format),
);
```

```zig
// Main loop
while (...) {
    zimgui.backend.newFrame(framebuffer_width, framebuffer_height);

    zimgui.bulletText(
        "Average :  {d:.3} ms/frame ({d:.1} fps)",
        .{ demo.gctx.stats.average_cpu_time, demo.gctx.stats.fps },
    );
    zimgui.bulletText("W, A, S, D :  move camera", .{});
    zimgui.spacing();

    if (zimgui.button("Setup Scene", .{})) {
        // Button pressed.
    }

    if (zimgui.dragFloat("Drag 1", .{ .v = &value0 })) {
        // value0 has changed
    }

    if (zimgui.dragFloat("Drag 2", .{ .v = &value0, .min = -1.0, .max = 1.0 })) {
        // value1 has changed
    }

    // Setup wgpu render pass here

    zimgui.backend.draw(pass);
}
```

### Building a shared library

If your project spans multiple zig modules that both use ImGui, such as an exe paired with a dll, you may want to build the `zimgui` dependencies (`zimgui_pkg.zimgui_c_cpp`) as a shared library. This can be enabled with the `shared` build option. Then, in `build.zig`, use `zimgui_pkg.link` to link `zimgui` to all the modules that use ImGui.

When built this way, the ImGui context will be located in the shared library. However, the `zimgui` zig code (which is compiled separately into each module) requires its own memory buffer which has to be initialized separately with `initNoContext`.

In your executable:
```zig
const zimgui = @import("zimgui");
zimgui.init(allocator);
defer zimgui.deinit();
```

In your shared library:
```zig
const zimgui = @import("zimgui");
zimgui.initNoContext(allocator);
defer zimgui.deinitNoContxt();
```

### DrawList API

```zig
draw_list.addQuad(.{
    .p1 = .{ 170, 420 },
    .p2 = .{ 270, 420 },
    .p3 = .{ 220, 520 },
    .p4 = .{ 120, 520 },
    .col = 0xff_00_00_ff,
    .thickness = 3.0,
});
draw_list.addText(.{ 130, 130 }, 0xff_00_00_ff, "The number is: {}", .{7});
draw_list.addCircleFilled(.{ .p = .{ 200, 600 }, .r = 50, .col = 0xff_ff_ff_ff });
draw_list.addCircle(.{ .p = .{ 200, 600 }, .r = 30, .col = 0xff_00_00_ff, .thickness = 11 });
draw_list.addPolyline(
    &.{ .{ 100, 700 }, .{ 200, 600 }, .{ 300, 700 }, .{ 400, 600 } },
    .{ .col = 0xff_00_aa_11, .thickness = 7 },
);
```
### Plot API
```zig
if (zimgui.plot.beginPlot("Line Plot", .{ .h = -1.0 })) {
    zimgui.plot.setupAxis(.x1, .{ .label = "xaxis" });
    zimgui.plot.setupAxisLimits(.x1, .{ .min = 0, .max = 5 });
    zimgui.plot.setupLegend(.{ .south = true, .west = true }, .{});
    zimgui.plot.setupFinish();
    zimgui.plot.plotLineValues("y data", i32, .{ .v = &.{ 0, 1, 0, 1, 0, 1 } });
    zimgui.plot.plotLine("xy data", f32, .{
        .xv = &.{ 0.1, 0.2, 0.5, 2.5 },
        .yv = &.{ 0.1, 0.3, 0.5, 0.9 },
    });
    zimgui.plot.endPlot();
}
```

### Test Engine API
Zig wraper for [ImGUI test engine](https://github.com/ocornut/imgui_test_engine).

```zig
var check_b = false;
var _te: *zimgui.te.TestEngine = zimgui.te.getTestEngine().?;
fn registerTests() void {
    _ = _te.registerTest(
        "Awesome",
        "should_do_some_another_magic",
        @src(),
        struct {
            pub fn gui(ctx: *zimgui.te.TestContext) !void {
                _ = ctx; // autofix
                _ = zimgui.begin("Test Window", .{ .flags = .{ .no_saved_settings = true } });
                defer zimgui.end();

                zimgui.text("Hello, automation world", .{});
                _ = zimgui.button("Click Me", .{});
                if (zimgui.treeNode("Node")) {
                    defer zimgui.treePop();

                    _ = zimgui.checkbox("Checkbox", .{ .v = &check_b });
                }
            }

            pub fn run(ctx: *zimgui.te.TestContext) !void {
                ctx.setRef("/Test Window");
                ctx.windowFocus("");

                ctx.itemAction(.click, "Click Me", .{}, null);
                ctx.itemAction(.open, "Node", .{}, null);
                ctx.itemAction(.check, "Node/Checkbox", .{}, null);
                ctx.itemAction(.uncheck, "Node/Checkbox", .{}, null);

                std.testing.expect(true) catch |err| {
                    zimgui.te.checkTestError(@src(), err);
                    return;
                };
            }
        },
    );
}
```
