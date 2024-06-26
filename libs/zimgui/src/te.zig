const std = @import("std");
const zimgui = @import("zimgui.zig");
const te_enabled = @import("zimgui_options").with_te;

pub const Actions = enum(c_int) {
    unknown = 0,
    /// Move mouse
    hover,
    /// Move mouse and click
    click,
    /// Move mouse and double-click
    double_click,
    /// Check item if unchecked (Checkbox, MenuItem or any widget reporting ImGuiItemStatusFlags_Checkable)
    check,
    /// Uncheck item if checked
    uncheck,
    /// Open item if closed (TreeNode, BeginMenu or any widget reporting ImGuiItemStatusFlags_Openable)
    open,
    /// Close item if opened
    close,
    /// Start text inputing into a field (e.g. CTRL+Click on Drags/Slider, click on InputText etc.)
    input,
    /// Activate item with navigation
    nav_activate,
};

pub const TestRunFlags = packed struct(c_int) {
    /// Used internally to temporarily disable the GUI func (at the end of a test, etc)
    gui_func_disable: bool = false,
    /// Set when user selects "Run GUI func"
    gui_func_only: bool = false,
    no_success_mgs: bool = false,
    no_stop_on_error: bool = false,
    no_break_on_error: bool = false,
    /// Disable input submission to let test submission raw input event (in order to test e.g. IO queue)
    enable_raw_inputs: bool = false,
    manual_run: bool = false,
    command_line: bool = false,
    _padding: u24 = 0,
};

pub const TestOpFlags = packed struct(c_int) {
    // Don't check for HoveredId after aiming for a widget. A few situations may want this: while e.g. dragging or another items prevents hovering, or for items that don't use ItemHoverable()
    no_check_hovered_id: bool = false,
    /// Don't abort/error e.g. if the item cannot be found or the operation doesn't succeed.
    no_error: bool = false,
    /// Don't focus window when aiming at an item
    no_focus_window: bool = false,
    /// Disable automatically uncollapsing windows (useful when specifically testing Collapsing behaviors)
    no_auto_uncollapse: bool = false,
    /// Disable automatically opening intermediaries (e.g. ItemClick("Hello/OK") will automatically first open "Hello" if "OK" isn't found. Only works if ref is a string path.
    no_auto_open_full_path: bool = false,
    /// Used by recursing functions to indicate a second attempt
    is_second_attempt: bool = false,
    move_to_edge_l: bool = false, // Simple Dumb aiming helpers to test widget that care about clicking position. May need to replace will better functionalities.
    move_to_edge_r: bool = false,
    move_to_edge_u: bool = false,
    move_to_edge_d: bool = false,
    _padding: u22 = 0,
};

pub const CheckFlags = packed struct(c_int) {
    silent_success: bool = false,
    _padding: u31 = 0,
};

pub const RunSpeed = enum(c_int) {
    /// Run tests as fast as possible (teleport mouse, skip delays, etc.)
    fast = 0,
    /// Run tests at human watchable speed (for debugging)
    normal = 1,
    /// Run tests with pauses between actions (for e.g. tutorials)
    cinematic = 2,
};

pub const TestGroup = enum(c_int) {
    unknown = -1,
    tests = 0,
    perfs = 1,
};

pub const Test = anyopaque;

pub const TestEngine = opaque {
    pub fn registerTest(
        engine: *TestEngine,
        category: [:0]const u8,
        name: [:0]const u8,
        src: std.builtin.SourceLocation,
        comptime Callbacks: type,
    ) *Test {
        return zimguiTe_RegisterTest(
            engine,
            category.ptr,
            name.ptr,
            src.file.ptr,
            @intCast(src.line),
            if (std.meta.hasFn(Callbacks, "gui"))
                struct {
                    fn f(context: *TestContext) callconv(.C) void {
                        Callbacks.gui(context) catch undefined;
                    }
                }.f
            else
                null,
            if (std.meta.hasFn(Callbacks, "run"))
                struct {
                    fn f(context: *TestContext) callconv(.C) void {
                        Callbacks.run(context) catch undefined;
                    }
                }.f
            else
                null,
        );
    }

    pub const showTestEngineWindows = zimguiTe_ShowTestEngineWindows;
    extern fn zimguiTe_ShowTestEngineWindows(engine: *TestEngine, p_open: ?*bool) void;

    pub const setRunSpeed = zimguiTe_EngineSetRunSpeed;
    extern fn zimguiTe_EngineSetRunSpeed(engine: *TestEngine, speed: RunSpeed) void;

    pub const stop = zimguiTe_Stop;
    extern fn zimguiTe_Stop(engine: *TestEngine) void;

    pub const tryAbortEngine = zimguiTe_TryAbortEngine;
    extern fn zimguiTe_TryAbortEngine(engine: *TestEngine) void;

    pub const postSwap = zimguiTe_PostSwap;
    extern fn zimguiTe_PostSwap(engine: *TestEngine) void;

    pub const isTestQueueEmpty = zimguiTe_IsTestQueueEmpty;
    extern fn zimguiTe_IsTestQueueEmpty(engine: *TestEngine) bool;

    pub const getResult = zimguiTe_GetResult;
    extern fn zimguiTe_GetResult(engine: *TestEngine, count_tested: *c_int, count_success: *c_int) void;

    pub const printResultSummary = zimguiTe_PrintResultSummary;
    extern fn zimguiTe_PrintResultSummary(engine: *TestEngine) void;

    pub fn queueTests(engine: *TestEngine, group: TestGroup, filter_str: [:0]const u8, run_flags: TestRunFlags) void {
        zimguiTe_QueueTests(engine, group, filter_str.ptr, run_flags);
    }
    extern fn zimguiTe_QueueTests(engine: *TestEngine, group: TestGroup, filter_str: [*]const u8, run_flags: TestRunFlags) void;

    pub fn exportJunitResult(engine: *TestEngine, filename: [:0]const u8) void {
        zimguiTe_EngineExportJunitResult(engine, filename.ptr);
    }
    extern fn zimguiTe_EngineExportJunitResult(engine: *TestEngine, filename: [*]const u8) void;
};

pub const TestContext = opaque {
    pub fn setRef(ctx: *TestContext, ref: [:0]const u8) void {
        return zimguiTe_ContextSetRef(ctx, ref.ptr);
    }

    pub fn windowFocus(ctx: *TestContext, ref: [:0]const u8) void {
        return zimguiTe_ContextWindowFocus(ctx, ref.ptr);
    }

    pub fn yield(ctx: *TestContext, frame_count: i32) void {
        return zimguiTe_ContextYield(ctx, frame_count);
    }

    pub fn itemAction(ctx: *TestContext, action: Actions, ref: [:0]const u8, flags: TestOpFlags, action_arg: ?*anyopaque) void {
        return zimguiTe_ContextItemAction(ctx, action, ref.ptr, flags, action_arg);
    }

    pub fn itemInputStrValue(ctx: *TestContext, ref: [:0]const u8, value: [:0]const u8) void {
        return zimguiTe_ContextItemInputStrValue(ctx, ref.ptr, value.ptr);
    }

    pub fn itemInputIntValue(ctx: *TestContext, ref: [:0]const u8, value: i32) void {
        return zimguiTe_ContextItemInputIntValue(ctx, ref.ptr, value);
    }

    pub fn itemInputFloatValue(ctx: *TestContext, ref: [:0]const u8, value: f32) void {
        return zimguiTe_ContextItemInputFloatValue(ctx, ref.ptr, value);
    }

    pub fn menuAction(ctx: *TestContext, action: Actions, ref: [*]const u8) void {
        return zimguiTe_ContextMenuAction(ctx, action, ref);
    }

    pub fn dragAndDrop(ctx: *TestContext, ref_src: [:0]const u8, ref_dst: [:0]const u8, button: zimgui.MouseButton) void {
        return zimguiTe_ContextDragAndDrop(ctx, ref_src.ptr, ref_dst.ptr, button);
    }

    pub fn keyDown(ctx: *TestContext, key_chord: c_int) void {
        return zimguiTe_ContextKeyDown(ctx, key_chord);
    }

    pub fn keyUp(ctx: *TestContext, key_chord: c_int) void {
        return zimguiTe_ContextKeyUp(ctx, key_chord);
    }

    extern fn zimguiTe_ContextSetRef(ctx: *TestContext, ref: [*]const u8) void;
    extern fn zimguiTe_ContextWindowFocus(ctx: *TestContext, ref: [*]const u8) void;
    extern fn zimguiTe_ContextYield(ctx: *TestContext, frame_count: c_int) void;
    extern fn zimguiTe_ContextMenuAction(ctx: *TestContext, action: Actions, ref: [*]const u8) void;
    extern fn zimguiTe_ContextItemAction(ctx: *TestContext, action: Actions, ref: [*]const u8, flags: TestOpFlags, action_arg: ?*anyopaque) void;
    extern fn zimguiTe_ContextItemInputStrValue(ctx: *TestContext, ref: [*]const u8, value: [*]const u8) void;
    extern fn zimguiTe_ContextItemInputIntValue(ctx: *TestContext, ref: [*]const u8, value: i32) void;
    extern fn zimguiTe_ContextItemInputFloatValue(ctx: *TestContext, ref: [*]const u8, value: f32) void;
    extern fn zimguiTe_ContextDragAndDrop(ctx: *TestContext, ref_src: [*]const u8, ref_dst: [*]const u8, button: zimgui.MouseButton) void;
    extern fn zimguiTe_ContextKeyDown(ctx: *TestContext, key_chord: c_int) void;
    extern fn zimguiTe_ContextKeyUp(ctx: *TestContext, key_chord: c_int) void;
};

const ImGuiTestGuiFunc = fn (context: *TestContext) callconv(.C) void;
const ImGuiTestTestFunc = fn (context: *TestContext) callconv(.C) void;

pub const createContext = zimguiTe_CreateContext;
extern fn zimguiTe_CreateContext() *TestEngine;

pub const destroyContext = zimguiTe_DestroyContext;
extern fn zimguiTe_DestroyContext(engine: *TestEngine) void;

extern fn zimguiTe_Check(filename: [*]const u8, func: [*]const u8, line: u32, flags: CheckFlags, resul: bool, expr: [*]const u8) bool;

pub fn check(src: std.builtin.SourceLocation, flags: CheckFlags, resul: bool, expr: [:0]const u8) bool {
    return zimguiTe_Check(src.file.ptr, src.fn_name.ptr, src.line, flags, resul, expr.ptr);
}

pub extern fn zimguiTe_RegisterTest(
    engine: *TestEngine,
    category: [*]const u8,
    name: [*]const u8,
    src: [*]const u8,
    src_line: c_int,
    gui_fce: ?*const ImGuiTestGuiFunc,
    gui_test_fce: ?*const ImGuiTestTestFunc,
) *Test;

pub fn checkTestError(
    src: std.builtin.SourceLocation,
    err: anyerror,
) void {
    var buff: [128:0]u8 = undefined;
    const msg = std.fmt.bufPrintZ(&buff, "Assert error: {}", .{err}) catch undefined;
    _ = zimguiTe_Check(src.file.ptr, src.fn_name.ptr, src.line, .{}, false, msg.ptr);
}

var _te_engine: ?*TestEngine = null;
pub fn getTestEngine() ?*TestEngine {
    return _te_engine;
}

pub fn init() void {
    _te_engine = createContext();
}

pub fn deinit() void {
    destroyContext(_te_engine.?);
}
