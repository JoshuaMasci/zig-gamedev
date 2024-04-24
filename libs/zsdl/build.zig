const builtin = @import("builtin");
const std = @import("std");
const assert = std.debug.assert;

pub fn build(b: *std.Build) !void {
    _ = b.addModule("zsdl2", .{
        .root_source_file = .{ .path = "src/sdl2.zig" },
        .imports = &.{},
    });

    _ = b.addModule("zsdl2_ttf", .{
        .root_source_file = .{ .path = "src/sdl2.zig" },
        .imports = &.{},
    });

    _ = b.addModule("zsdl3", .{
        .root_source_file = .{ .path = "src/sdl3.zig" },
        .imports = &.{},
    });
}

pub fn link_SDL2(compile_step: *std.Build.Step.Compile) void {
    switch (compile_step.rootModuleTarget().os.tag) {
        .windows => {
            compile_step.linkSystemLibrary("SDL2");
            compile_step.linkSystemLibrary("SDL2main");
        },
        .linux => {
            compile_step.linkSystemLibrary("SDL2");
            compile_step.root_module.addRPathSpecial("$ORIGIN");
        },
        .macos => {
            compile_step.linkFramework("SDL2");
            compile_step.root_module.addRPathSpecial("@executable_path");
        },
        else => {},
    }
}

pub fn link_SDL2_ttf(compile_step: *std.Build.Step.Compile) void {
    switch (compile_step.rootModuleTarget().os.tag) {
        .windows => {
            compile_step.linkSystemLibrary("SDL2_ttf");
        },
        .linux => {
            compile_step.linkSystemLibrary("SDL2_ttf");
            compile_step.root_module.addRPathSpecial("$ORIGIN");
        },
        .macos => {
            compile_step.linkFramework("SDL2_ttf");
            compile_step.root_module.addRPathSpecial("@executable_path");
        },
        else => {},
    }
}

pub fn link_SDL3(compile_step: *std.Build.Step.Compile) void {
    switch (compile_step.rootModuleTarget().os.tag) {
        .windows => {
            compile_step.linkSystemLibrary("SDL3");
        },
        .linux => {
            compile_step.linkSystemLibrary("SDL3");
            compile_step.root_module.addRPathSpecial("$ORIGIN");
        },
        .macos => {
            compile_step.linkFramework("SDL3");
            compile_step.root_module.addRPathSpecial("@executable_path");
        },
        else => {},
    }
}
