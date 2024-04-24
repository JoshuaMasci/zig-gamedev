const gui = @import("gui.zig");

pub fn init(
    window: *const anyopaque,
    gl_context: *const anyopaque,
) void {
    _ = ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
    ImGui_ImplOpenGL3_Init(null);
}

pub fn deinit() void {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
}

pub fn newFrame(fb_size: [2]u32) void {
    ImGui_ImplSDL2_NewFrame();
    ImGui_ImplOpenGL3_NewFrame();

    gui.io.setDisplaySize(@floatFromInt(fb_size[0]), @floatFromInt(fb_size[1]));
    gui.io.setDisplayFramebufferScale(1.0, 1.0);

    gui.newFrame();
}

pub fn processEvent(event: *const anyopaque) bool {
    return ImGui_ImplSDL2_ProcessEvent(@ptrCast(event));
}

pub fn draw() void {
    gui.render();
    ImGui_ImplOpenGL3_RenderDrawData(gui.getDrawData());
}

extern fn ImGui_ImplSDL2_InitForOpenGL(window: *const anyopaque, gl_context: *const anyopaque) bool;
extern fn ImGui_ImplSDL2_Shutdown() void;
extern fn ImGui_ImplSDL2_NewFrame() void;
extern fn ImGui_ImplSDL2_ProcessEvent(data: *const anyopaque) bool;

// Those functions are defined in 'imgui_impl_opengl3.cpp`
// (they include few custom changes).
extern fn ImGui_ImplOpenGL3_Init(glsl_version: [*c]const u8) void;
extern fn ImGui_ImplOpenGL3_Shutdown() void;
extern fn ImGui_ImplOpenGL3_NewFrame() void;
extern fn ImGui_ImplOpenGL3_RenderDrawData(data: *const anyopaque) void;
