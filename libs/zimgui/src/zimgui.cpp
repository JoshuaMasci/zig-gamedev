#include "imgui.h"

#if ZIMGUI_IMPLOT
#include "implot.h"
#endif

#if ZIMGUI_TE
#include "imgui_te_engine.h"
#include "imgui_te_context.h"
#include "imgui_te_ui.h"
#include "imgui_te_utils.h"
#include "imgui_te_exporters.h"
#endif

#include "imgui_internal.h"

#ifndef ZIMGUI_API
#define ZIMGUI_API
#endif

extern "C" {

/*
#include <stdio.h>

ZIMGUI_API float zimguiGetFloatMin(void) {
    printf("__FLT_MIN__ %.32e\n", __FLT_MIN__);
    return __FLT_MIN__;
}

ZIMGUI_API float zimguiGetFloatMax(void) {
    printf("__FLT_MAX__ %.32e\n", __FLT_MAX__);
    return __FLT_MAX__;
}
*/

ZIMGUI_API void zimguiSetAllocatorFunctions(
    void* (*alloc_func)(size_t, void*),
    void (*free_func)(void*, void*)
) {
    ImGui::SetAllocatorFunctions(alloc_func, free_func, nullptr);
}

ZIMGUI_API void zimguiSetNextWindowPos(float x, float y, ImGuiCond cond, float pivot_x, float pivot_y) {
    ImGui::SetNextWindowPos({ x, y }, cond, { pivot_x, pivot_y });
}

ZIMGUI_API void zimguiSetNextWindowSize(float w, float h, ImGuiCond cond) {
    ImGui::SetNextWindowSize({ w, h }, cond);
}

ZIMGUI_API void zimguiSetNextWindowCollapsed(bool collapsed, ImGuiCond cond) {
    ImGui::SetNextWindowCollapsed(collapsed, cond);
}

ZIMGUI_API void zimguiSetNextWindowFocus(void) {
    ImGui::SetNextWindowFocus();
}

ZIMGUI_API void zimguiSetNextWindowBgAlpha(float alpha) {
    ImGui::SetNextWindowBgAlpha(alpha);
}

ZIMGUI_API void zimguiSetKeyboardFocusHere(int offset) {
    ImGui::SetKeyboardFocusHere(offset);
}

ZIMGUI_API bool zimguiBegin(const char* name, bool* p_open, ImGuiWindowFlags flags) {
    return ImGui::Begin(name, p_open, flags);
}

ZIMGUI_API void zimguiEnd(void) {
    ImGui::End();
}

ZIMGUI_API bool zimguiBeginChild(const char* str_id, float w, float h, ImGuiChildFlags child_flags, ImGuiWindowFlags window_flags) {
    return ImGui::BeginChild(str_id, { w, h }, child_flags, window_flags);
}

ZIMGUI_API bool zimguiBeginChildId(ImGuiID id, float w, float h, ImGuiChildFlags child_flags, ImGuiWindowFlags window_flags) {
    return ImGui::BeginChild(id, { w, h }, child_flags, window_flags);
}

ZIMGUI_API void zimguiEndChild(void) {
    ImGui::EndChild();
}

ZIMGUI_API float zimguiGetScrollX(void) {
    return ImGui::GetScrollX();
}

ZIMGUI_API float zimguiGetScrollY(void) {
    return ImGui::GetScrollY();
}

ZIMGUI_API void zimguiSetScrollX(float scroll_x) {
    ImGui::SetScrollX(scroll_x);
}

ZIMGUI_API void zimguiSetScrollY(float scroll_y) {
    ImGui::SetScrollY(scroll_y);
}

ZIMGUI_API float zimguiGetScrollMaxX(void) {
    return ImGui::GetScrollMaxX();
}

ZIMGUI_API float zimguiGetScrollMaxY(void) {
    return ImGui::GetScrollMaxY();
}

ZIMGUI_API void zimguiSetScrollHereX(float center_x_ratio) {
    ImGui::SetScrollHereX(center_x_ratio);
}

ZIMGUI_API void zimguiSetScrollHereY(float center_y_ratio) {
    ImGui::SetScrollHereY(center_y_ratio);
}

ZIMGUI_API void zimguiSetScrollFromPosX(float local_x, float center_x_ratio) {
    ImGui::SetScrollFromPosX(local_x, center_x_ratio);
}

ZIMGUI_API void zimguiSetScrollFromPosY(float local_y, float center_y_ratio) {
    ImGui::SetScrollFromPosY(local_y, center_y_ratio);
}

ZIMGUI_API bool zimguiIsWindowAppearing(void) {
    return ImGui::IsWindowAppearing();
}

ZIMGUI_API bool zimguiIsWindowCollapsed(void) {
    return ImGui::IsWindowCollapsed();
}

ZIMGUI_API bool zimguiIsWindowFocused(ImGuiFocusedFlags flags) {
    return ImGui::IsWindowFocused(flags);
}

ZIMGUI_API bool zimguiIsWindowHovered(ImGuiHoveredFlags flags) {
    return ImGui::IsWindowHovered(flags);
}

ZIMGUI_API void zimguiGetWindowPos(float pos[2]) {
    const ImVec2 p = ImGui::GetWindowPos();
    pos[0] = p.x;
    pos[1] = p.y;
}

ZIMGUI_API void zimguiGetWindowSize(float size[2]) {
    const ImVec2 s = ImGui::GetWindowSize();
    size[0] = s.x;
    size[1] = s.y;
}

ZIMGUI_API float zimguiGetWindowWidth(void) {
    return ImGui::GetWindowWidth();
}

ZIMGUI_API float zimguiGetWindowHeight(void) {
    return ImGui::GetWindowHeight();
}

ZIMGUI_API void zimguiGetMouseDragDelta(ImGuiMouseButton button, float lock_threshold, float delta[2]) {
    const ImVec2 d = ImGui::GetMouseDragDelta(button, lock_threshold);
    delta[0] = d.x;
    delta[1] = d.y;
}

ZIMGUI_API void zimguiResetMouseDragDelta(ImGuiMouseButton button) {
    ImGui::ResetMouseDragDelta(button);
}

ZIMGUI_API void zimguiSpacing(void) {
    ImGui::Spacing();
}

ZIMGUI_API void zimguiNewLine(void) {
    ImGui::NewLine();
}

ZIMGUI_API void zimguiIndent(float indent_w) {
    ImGui::Indent(indent_w);
}

ZIMGUI_API void zimguiUnindent(float indent_w) {
    ImGui::Unindent(indent_w);
}

ZIMGUI_API void zimguiSeparator(void) {
    ImGui::Separator();
}

ZIMGUI_API void zimguiSeparatorText(const char* label) {
    ImGui::SeparatorText(label);
}

ZIMGUI_API void zimguiSameLine(float offset_from_start_x, float spacing) {
    ImGui::SameLine(offset_from_start_x, spacing);
}

ZIMGUI_API void zimguiDummy(float w, float h) {
    ImGui::Dummy({ w, h });
}

ZIMGUI_API void zimguiBeginGroup(void) {
    ImGui::BeginGroup();
}

ZIMGUI_API void zimguiEndGroup(void) {
    ImGui::EndGroup();
}

ZIMGUI_API void zimguiGetItemRectMax(float rect[2]) {
    const ImVec2 r = ImGui::GetItemRectMax();
    rect[0] = r.x;
    rect[1] = r.y;
}

ZIMGUI_API void zimguiGetItemRectMin(float rect[2]) {
    const ImVec2 r = ImGui::GetItemRectMin();
    rect[0] = r.x;
    rect[1] = r.y;
}

ZIMGUI_API void zimguiGetItemRectSize(float rect[2]) {
    const ImVec2 r = ImGui::GetItemRectSize();
    rect[0] = r.x;
    rect[1] = r.y;
}

ZIMGUI_API void zimguiGetCursorPos(float pos[2]) {
    const ImVec2 p = ImGui::GetCursorPos();
    pos[0] = p.x;
    pos[1] = p.y;
}

ZIMGUI_API float zimguiGetCursorPosX(void) {
    return ImGui::GetCursorPosX();
}

ZIMGUI_API float zimguiGetCursorPosY(void) {
    return ImGui::GetCursorPosY();
}

ZIMGUI_API void zimguiSetCursorPos(float local_x, float local_y) {
    ImGui::SetCursorPos({ local_x, local_y });
}

ZIMGUI_API void zimguiSetCursorPosX(float local_x) {
    ImGui::SetCursorPosX(local_x);
}

ZIMGUI_API void zimguiSetCursorPosY(float local_y) {
    ImGui::SetCursorPosY(local_y);
}

ZIMGUI_API void zimguiGetCursorStartPos(float pos[2]) {
    const ImVec2 p = ImGui::GetCursorStartPos();
    pos[0] = p.x;
    pos[1] = p.y;
}

ZIMGUI_API void zimguiGetCursorScreenPos(float pos[2]) {
    const ImVec2 p = ImGui::GetCursorScreenPos();
    pos[0] = p.x;
    pos[1] = p.y;
}

ZIMGUI_API void zimguiSetCursorScreenPos(float screen_x, float screen_y) {
    ImGui::SetCursorScreenPos({ screen_x, screen_y });
}

ZIMGUI_API int zimguiGetMouseCursor(void) {
    return ImGui::GetMouseCursor();
}

ZIMGUI_API void zimguiSetMouseCursor(int cursor) {
    ImGui::SetMouseCursor(cursor);
}

ZIMGUI_API void zimguiGetMousePos(float pos[2]) {
    const ImVec2 p = ImGui::GetMousePos();
    pos[0] = p.x;
    pos[1] = p.y;
}

ZIMGUI_API void zimguiAlignTextToFramePadding(void) {
    ImGui::AlignTextToFramePadding();
}

ZIMGUI_API float zimguiGetTextLineHeight(void) {
    return ImGui::GetTextLineHeight();
}

ZIMGUI_API float zimguiGetTextLineHeightWithSpacing(void) {
    return ImGui::GetTextLineHeightWithSpacing();
}

ZIMGUI_API float zimguiGetFrameHeight(void) {
    return ImGui::GetFrameHeight();
}

ZIMGUI_API float zimguiGetFrameHeightWithSpacing(void) {
    return ImGui::GetFrameHeightWithSpacing();
}

ZIMGUI_API bool zimguiDragFloat(
    const char* label,
    float* v,
    float v_speed,
    float v_min,
    float v_max,
    const char* format,
    ImGuiSliderFlags flags
) {
    return ImGui::DragFloat(label, v, v_speed, v_min, v_max, format, flags);
}

ZIMGUI_API bool zimguiDragFloat2(
    const char* label,
    float v[2],
    float v_speed,
    float v_min,
    float v_max,
    const char* format,
    ImGuiSliderFlags flags
) {
    return ImGui::DragFloat2(label, v, v_speed, v_min, v_max, format, flags);
}

ZIMGUI_API bool zimguiDragFloat3(
    const char* label,
    float v[3],
    float v_speed,
    float v_min,
    float v_max,
    const char* format,
    ImGuiSliderFlags flags
) {
    return ImGui::DragFloat3(label, v, v_speed, v_min, v_max, format, flags);
}

ZIMGUI_API bool zimguiDragFloat4(
    const char* label,
    float v[4],
    float v_speed,
    float v_min,
    float v_max,
    const char* format,
    ImGuiSliderFlags flags
) {
    return ImGui::DragFloat4(label, v, v_speed, v_min, v_max, format, flags);
}

ZIMGUI_API bool zimguiDragFloatRange2(
    const char* label,
    float* v_current_min,
    float* v_current_max,
    float v_speed,
    float v_min,
    float v_max,
    const char* format,
    const char* format_max,
    ImGuiSliderFlags flags
) {
    return ImGui::DragFloatRange2(
        label,
        v_current_min,
        v_current_max,
        v_speed,
        v_min,
        v_max,
        format,
        format_max,
        flags
    );
}

ZIMGUI_API bool zimguiDragInt(
    const char* label,
    int* v,
    float v_speed,
    int v_min,
    int v_max,
    const char* format,
    ImGuiSliderFlags flags
) {
    return ImGui::DragInt(label, v, v_speed, v_min, v_max, format, flags);
}

ZIMGUI_API bool zimguiDragInt2(
    const char* label,
    int v[2],
    float v_speed,
    int v_min,
    int v_max,
    const char* format,
    ImGuiSliderFlags flags
) {
    return ImGui::DragInt2(label, v, v_speed, v_min, v_max, format, flags);
}

ZIMGUI_API bool zimguiDragInt3(
    const char* label,
    int v[3],
    float v_speed,
    int v_min,
    int v_max,
    const char* format,
    ImGuiSliderFlags flags
) {
    return ImGui::DragInt3(label, v, v_speed, v_min, v_max, format, flags);
}

ZIMGUI_API bool zimguiDragInt4(
    const char* label,
    int v[4],
    float v_speed,
    int v_min,
    int v_max,
    const char* format,
    ImGuiSliderFlags flags
) {
    return ImGui::DragInt4(label, v, v_speed, v_min, v_max, format, flags);
}

ZIMGUI_API bool zimguiDragIntRange2(
    const char* label,
    int* v_current_min,
    int* v_current_max,
    float v_speed,
    int v_min,
    int v_max,
    const char* format,
    const char* format_max,
    ImGuiSliderFlags flags
) {
    return ImGui::DragIntRange2(
        label,
        v_current_min,
        v_current_max,
        v_speed,
        v_min,
        v_max,
        format,
        format_max,
        flags
    );
}

ZIMGUI_API bool zimguiDragScalar(
    const char* label,
    ImGuiDataType data_type,
    void* p_data,
    float v_speed,
    const void* p_min,
    const void* p_max,
    const char* format,
    ImGuiSliderFlags flags
) {
    return ImGui::DragScalar(label, data_type, p_data, v_speed, p_min, p_max, format, flags);
}

ZIMGUI_API bool zimguiDragScalarN(
    const char* label,
    ImGuiDataType data_type,
    void* p_data,
    int components,
    float v_speed,
    const void* p_min,
    const void* p_max,
    const char* format,
    ImGuiSliderFlags flags
) {
    return ImGui::DragScalarN(label, data_type, p_data, components, v_speed, p_min, p_max, format, flags);
}

ZIMGUI_API bool zimguiBeginDragDropSource(ImGuiDragDropFlags flags = 0) {
  return ImGui::BeginDragDropSource(flags);
}
ZIMGUI_API bool zimguiSetDragDropPayload(
    const char* type,
    const void* data,
    size_t sz,
    ImGuiCond cond = 0
) {
  return ImGui::SetDragDropPayload(type, data, sz, cond);
}
ZIMGUI_API void zimguiEndDragDropSource() {
  return ImGui::EndDragDropSource();
}
ZIMGUI_API bool zimguiBeginDragDropTarget() {
  return ImGui::BeginDragDropTarget();
}
ZIMGUI_API const ImGuiPayload* zimguiAcceptDragDropPayload(
    const char* type,
    ImGuiDragDropFlags flags = 0
) {
  return ImGui::AcceptDragDropPayload(type);
}
ZIMGUI_API void zimguiEndDragDropTarget() {
  return ImGui::EndDragDropTarget();
}
ZIMGUI_API const ImGuiPayload* zimguiGetDragDropPayload() {
  return ImGui::GetDragDropPayload();
}

ZIMGUI_API void zimguiImGuiPayload_Clear(ImGuiPayload* payload) { payload->Clear(); }

ZIMGUI_API bool zimguiImGuiPayload_IsDataType(const ImGuiPayload* payload, const char* type) {
  return payload->IsDataType(type);
}

ZIMGUI_API bool zimguiImGuiPayload_IsPreview(const ImGuiPayload* payload) {
  return payload->IsPreview();
}

ZIMGUI_API bool zimguiImGuiPayload_IsDelivery(const ImGuiPayload* payload) {
  return payload->IsDelivery();
}


ZIMGUI_API bool zimguiCombo(
    const char* label,
    int* current_item,
    const char* items_separated_by_zeros,
    int popup_max_height_in_items
) {
    return ImGui::Combo(label, current_item, items_separated_by_zeros, popup_max_height_in_items);
}

ZIMGUI_API bool zimguiBeginCombo(const char* label, const char* preview_value, ImGuiComboFlags flags) {
    return ImGui::BeginCombo(label, preview_value, flags);
}

ZIMGUI_API void zimguiEndCombo(void) {
    ImGui::EndCombo();
}

ZIMGUI_API bool zimguiBeginListBox(const char* label, float w, float h) {
    return ImGui::BeginListBox(label, { w, h });
}

ZIMGUI_API void zimguiEndListBox(void) {
    ImGui::EndListBox();
}

ZIMGUI_API bool zimguiSelectable(const char* label, bool selected, ImGuiSelectableFlags flags, float w, float h) {
    return ImGui::Selectable(label, selected, flags, { w, h });
}

ZIMGUI_API bool zimguiSelectableStatePtr(
    const char* label,
    bool* p_selected,
    ImGuiSelectableFlags flags,
    float w,
    float h
) {
    return ImGui::Selectable(label, p_selected, flags, { w, h });
}

ZIMGUI_API bool zimguiSliderFloat(
    const char* label,
    float* v,
    float v_min,
    float v_max,
    const char* format,
    ImGuiSliderFlags flags
) {
    return ImGui::SliderFloat(label, v, v_min, v_max, format, flags);
}

ZIMGUI_API bool zimguiSliderFloat2(
    const char* label,
    float v[2],
    float v_min,
    float v_max,
    const char* format,
    ImGuiSliderFlags flags
) {
    return ImGui::SliderFloat2(label, v, v_min, v_max, format, flags);
}

ZIMGUI_API bool zimguiSliderFloat3(
    const char* label,
    float v[3],
    float v_min,
    float v_max,
    const char* format,
    ImGuiSliderFlags flags
) {
    return ImGui::SliderFloat3(label, v, v_min, v_max, format, flags);
}

ZIMGUI_API bool zimguiSliderFloat4(
    const char* label,
    float v[4],
    float v_min,
    float v_max,
    const char* format,
    ImGuiSliderFlags flags
) {
    return ImGui::SliderFloat4(label, v, v_min, v_max, format, flags);
}

ZIMGUI_API bool zimguiSliderInt(
    const char* label,
    int* v,
    int v_min,
    int v_max,
    const char* format,
    ImGuiSliderFlags flags
) {
    return ImGui::SliderInt(label, v, v_min, v_max, format, flags);
}

ZIMGUI_API bool zimguiSliderInt2(
    const char* label,
    int v[2],
    int v_min,
    int v_max,
    const char* format,
    ImGuiSliderFlags flags
) {
    return ImGui::SliderInt2(label, v, v_min, v_max, format, flags);
}

ZIMGUI_API bool zimguiSliderInt3(
    const char* label,
    int v[3],
    int v_min,
    int v_max,
    const char* format,
    ImGuiSliderFlags flags
) {
    return ImGui::SliderInt3(label, v, v_min, v_max, format, flags);
}

ZIMGUI_API bool zimguiSliderInt4(
    const char* label,
    int v[4],
    int v_min,
    int v_max,
    const char* format,
    ImGuiSliderFlags flags
) {
    return ImGui::SliderInt4(label, v, v_min, v_max, format, flags);
}

ZIMGUI_API bool zimguiSliderScalar(
    const char* label,
    ImGuiDataType data_type,
    void* p_data,
    const void* p_min,
    const void* p_max,
    const char* format,
    ImGuiSliderFlags flags
) {
    return ImGui::SliderScalar(label, data_type, p_data, p_min, p_max, format, flags);
}

ZIMGUI_API bool zimguiSliderScalarN(
    const char* label,
    ImGuiDataType data_type,
    void* p_data,
    int components,
    const void* p_min,
    const void* p_max,
    const char* format,
    ImGuiSliderFlags flags
) {
    return ImGui::SliderScalarN(label, data_type, p_data, components, p_min, p_max, format, flags);
}

ZIMGUI_API bool zimguiVSliderFloat(
    const char* label,
    float w,
    float h,
    float* v,
    float v_min,
    float v_max,
    const char* format,
    ImGuiSliderFlags flags
) {
    return ImGui::VSliderFloat(label, { w, h }, v, v_min, v_max, format, flags);
}

ZIMGUI_API bool zimguiVSliderInt(
    const char* label,
    float w,
    float h,
    int* v,
    int v_min,
    int v_max,
    const char* format,
    ImGuiSliderFlags flags
) {
    return ImGui::VSliderInt(label, { w, h }, v, v_min, v_max, format, flags);
}

ZIMGUI_API bool zimguiVSliderScalar(
    const char* label,
    float w,
    float h,
    ImGuiDataType data_type,
    void* p_data,
    const void* p_min,
    const void* p_max,
    const char* format,
    ImGuiSliderFlags flags
) {
    return ImGui::VSliderScalar(label, { w, h }, data_type, p_data, p_min, p_max, format, flags);
}

ZIMGUI_API bool zimguiSliderAngle(
    const char* label,
    float* v_rad,
    float v_degrees_min,
    float v_degrees_max,
    const char* format,
    ImGuiSliderFlags flags
) {
    return ImGui::SliderAngle(label, v_rad, v_degrees_min, v_degrees_max, format, flags);
}

ZIMGUI_API ImGuiInputTextCallbackData zimguiInputTextCallbackData_Init(void) {
    return ImGuiInputTextCallbackData();
}

ZIMGUI_API void zimguiInputTextCallbackData_DeleteChars(
    ImGuiInputTextCallbackData* data,
    int pos,
    int bytes_count
) {
    data->DeleteChars(pos, bytes_count);
}

ZIMGUI_API void zimguiInputTextCallbackData_InsertChars(
    ImGuiInputTextCallbackData* data,
    int pos,
    const char* text,
    const char* text_end
) {
    data->InsertChars(pos, text, text_end);
}

ZIMGUI_API bool zimguiInputText(
    const char* label,
    char* buf,
    size_t buf_size,
    ImGuiInputTextFlags flags,
    ImGuiInputTextCallback callback,
    void* user_data
) {
    return ImGui::InputText(label, buf, buf_size, flags, callback, user_data);
}

ZIMGUI_API bool zimguiInputTextMultiline(
    const char* label,
    char* buf,
    size_t buf_size,
    float w,
    float h,
    ImGuiInputTextFlags flags,
    ImGuiInputTextCallback callback,
    void* user_data
) {
    return ImGui::InputTextMultiline(label, buf, buf_size, { w, h }, flags, callback, user_data);
}

ZIMGUI_API bool zimguiInputTextWithHint(
    const char* label,
    const char* hint,
    char* buf,
    size_t buf_size,
    ImGuiInputTextFlags flags,
    ImGuiInputTextCallback callback,
    void* user_data
) {
    return ImGui::InputTextWithHint(label, hint, buf, buf_size, flags, callback, user_data);
}

ZIMGUI_API bool zimguiInputFloat(
    const char* label,
    float* v,
    float step,
    float step_fast,
    const char* format,
    ImGuiInputTextFlags flags
) {
    return ImGui::InputFloat(label, v, step, step_fast, format, flags);
}

ZIMGUI_API bool zimguiInputFloat2(
    const char* label,
    float v[2],
    const char* format,
    ImGuiInputTextFlags flags
) {
    return ImGui::InputFloat2(label, v, format, flags);
}

ZIMGUI_API bool zimguiInputFloat3(
    const char* label,
    float v[3],
    const char* format,
    ImGuiInputTextFlags flags
) {
    return ImGui::InputFloat3(label, v, format, flags);
}

ZIMGUI_API bool zimguiInputFloat4(
    const char* label,
    float v[4],
    const char* format,
    ImGuiInputTextFlags flags
) {
    return ImGui::InputFloat4(label, v, format, flags);
}

ZIMGUI_API bool zimguiInputInt(
    const char* label,
    int* v,
    int step,
    int step_fast,
    ImGuiInputTextFlags flags
) {
    return ImGui::InputInt(label, v, step, step_fast, flags);
}

ZIMGUI_API bool zimguiInputInt2(const char* label, int v[2], ImGuiInputTextFlags flags) {
    return ImGui::InputInt2(label, v, flags);
}

ZIMGUI_API bool zimguiInputInt3(const char* label, int v[3], ImGuiInputTextFlags flags) {
    return ImGui::InputInt3(label, v, flags);
}

ZIMGUI_API bool zimguiInputInt4(const char* label, int v[4], ImGuiInputTextFlags flags) {
    return ImGui::InputInt4(label, v, flags);
}

ZIMGUI_API bool zimguiInputDouble(
    const char* label,
    double* v,
    double step,
    double step_fast,
    const char* format,
    ImGuiInputTextFlags flags
) {
    return ImGui::InputDouble(label, v, step, step_fast, format, flags);
}

ZIMGUI_API bool zimguiInputScalar(
    const char* label,
    ImGuiDataType data_type,
    void* p_data,
    const void* p_step,
    const void* p_step_fast,
    const char* format,
    ImGuiInputTextFlags flags
) {
    return ImGui::InputScalar(label, data_type, p_data, p_step, p_step_fast, format, flags);
}

ZIMGUI_API bool zimguiInputScalarN(
    const char* label,
    ImGuiDataType data_type,
    void* p_data,
    int components,
    const void* p_step,
    const void* p_step_fast,
    const char* format,
    ImGuiInputTextFlags flags
) {
    return ImGui::InputScalarN(label, data_type, p_data, components, p_step, p_step_fast, format, flags);
}

ZIMGUI_API bool zimguiColorEdit3(const char* label, float col[3], ImGuiColorEditFlags flags) {
    return ImGui::ColorEdit3(label, col, flags);
}

ZIMGUI_API bool zimguiColorEdit4(const char* label, float col[4], ImGuiColorEditFlags flags) {
    return ImGui::ColorEdit4(label, col, flags);
}

ZIMGUI_API bool zimguiColorPicker3(const char* label, float col[3], ImGuiColorEditFlags flags) {
    return ImGui::ColorPicker3(label, col, flags);
}

ZIMGUI_API bool zimguiColorPicker4(const char* label, float col[4], ImGuiColorEditFlags flags, const float* ref_col) {
    return ImGui::ColorPicker4(label, col, flags, ref_col);
}

ZIMGUI_API bool zimguiColorButton(const char* desc_id, const float col[4], ImGuiColorEditFlags flags, float w, float h) {
    return ImGui::ColorButton(desc_id, { col[0], col[1], col[2], col[3] }, flags, { w, h });
}

ZIMGUI_API void zimguiTextUnformatted(const char* text, const char* text_end) {
    ImGui::TextUnformatted(text, text_end);
}

ZIMGUI_API void zimguiTextColored(const float col[4], const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    ImGui::TextColoredV({ col[0], col[1], col[2], col[3] }, fmt, args);
    va_end(args);
}

ZIMGUI_API void zimguiTextDisabled(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    ImGui::TextDisabledV(fmt, args);
    va_end(args);
}

ZIMGUI_API void zimguiTextWrapped(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    ImGui::TextWrappedV(fmt, args);
    va_end(args);
}

ZIMGUI_API void zimguiBulletText(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    ImGui::BulletTextV(fmt, args);
    va_end(args);
}

ZIMGUI_API void zimguiLabelText(const char* label, const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    ImGui::LabelTextV(label, fmt, args);
    va_end(args);
}

ZIMGUI_API void zimguiCalcTextSize(
    const char* txt,
    const char* txt_end,
    bool hide_text_after_double_hash,
    float wrap_width,
    float* out_w,
    float* out_h
) {
    assert(out_w && out_h);
    const ImVec2 s = ImGui::CalcTextSize(txt, txt_end, hide_text_after_double_hash, wrap_width);
    *out_w = s.x;
    *out_h = s.y;
}

ZIMGUI_API bool zimguiButton(const char* label, float x, float y) {
    return ImGui::Button(label, { x, y });
}

ZIMGUI_API bool zimguiSmallButton(const char* label) {
    return ImGui::SmallButton(label);
}

ZIMGUI_API bool zimguiInvisibleButton(const char* str_id, float w, float h, ImGuiButtonFlags flags) {
    return ImGui::InvisibleButton(str_id, { w, h }, flags);
}

ZIMGUI_API bool zimguiArrowButton(const char* str_id, ImGuiDir dir) {
    return ImGui::ArrowButton(str_id, dir);
}

ZIMGUI_API void zimguiImage(
    ImTextureID user_texture_id,
    float w,
    float h,
    const float uv0[2],
    const float uv1[2],
    const float tint_col[4],
    const float border_col[4]
) {
    ImGui::Image(
        user_texture_id,
        { w, h },
        { uv0[0], uv0[1] },
        { uv1[0], uv1[1] },
        { tint_col[0], tint_col[1], tint_col[2], tint_col[3] },
        { border_col[0], border_col[1], border_col[2], border_col[3] }
    );
}

ZIMGUI_API bool zimguiImageButton(
    const char* str_id,
    ImTextureID user_texture_id,
    float w,
    float h,
    const float uv0[2],
    const float uv1[2],
    const float bg_col[4],
    const float tint_col[4]
) {
    return ImGui::ImageButton(
        str_id,
        user_texture_id,
        { w, h },
        { uv0[0], uv0[1] },
        { uv1[0], uv1[1] },
        { bg_col[0], bg_col[1], bg_col[2], bg_col[3] },
        { tint_col[0], tint_col[1], tint_col[2], tint_col[3] }
    );
}

ZIMGUI_API void zimguiBullet(void) {
    ImGui::Bullet();
}

ZIMGUI_API bool zimguiRadioButton(const char* label, bool active) {
    return ImGui::RadioButton(label, active);
}

ZIMGUI_API bool zimguiRadioButtonStatePtr(const char* label, int* v, int v_button) {
    return ImGui::RadioButton(label, v, v_button);
}

ZIMGUI_API bool zimguiCheckbox(const char* label, bool* v) {
    return ImGui::Checkbox(label, v);
}

ZIMGUI_API bool zimguiCheckboxBits(const char* label, unsigned int* bits, unsigned int bits_value) {
    return ImGui::CheckboxFlags(label, bits, bits_value);
}

ZIMGUI_API void zimguiProgressBar(float fraction, float w, float h, const char* overlay) {
    return ImGui::ProgressBar(fraction, { w, h }, overlay);
}

ZIMGUI_API ImGuiContext* zimguiCreateContext(ImFontAtlas* shared_font_atlas) {
    return ImGui::CreateContext(shared_font_atlas);
}

ZIMGUI_API void zimguiDestroyContext(ImGuiContext* ctx) {
    ImGui::DestroyContext(ctx);
}

ZIMGUI_API ImGuiContext* zimguiGetCurrentContext(void) {
    return ImGui::GetCurrentContext();
}

ZIMGUI_API void zimguiSetCurrentContext(ImGuiContext* ctx) {
    ImGui::SetCurrentContext(ctx);
}

ZIMGUI_API void zimguiNewFrame(void) {
    ImGui::NewFrame();
}

ZIMGUI_API void zimguiRender(void) {
    ImGui::Render();
}

ZIMGUI_API ImDrawData* zimguiGetDrawData(void) {
    return ImGui::GetDrawData();
}

ZIMGUI_API void zimguiShowDemoWindow(bool* p_open) {
    ImGui::ShowDemoWindow(p_open);
}

ZIMGUI_API void zimguiBeginDisabled(bool disabled) {
    ImGui::BeginDisabled(disabled);
}

ZIMGUI_API void zimguiEndDisabled(void) {
    ImGui::EndDisabled();
}

ZIMGUI_API ImGuiStyle* zimguiGetStyle(void) {
    return &ImGui::GetStyle();
}

ZIMGUI_API ImGuiStyle zimguiStyle_Init(void) {
    return ImGuiStyle();
}

ZIMGUI_API void zimguiStyle_ScaleAllSizes(ImGuiStyle* style, float scale_factor) {
    style->ScaleAllSizes(scale_factor);
}

ZIMGUI_API void zimguiPushStyleColor4f(ImGuiCol idx, const float col[4]) {
    ImGui::PushStyleColor(idx, { col[0], col[1], col[2], col[3] });
}

ZIMGUI_API void zimguiPushStyleColor1u(ImGuiCol idx, ImU32 col) {
    ImGui::PushStyleColor(idx, col);
}

ZIMGUI_API void zimguiPopStyleColor(int count) {
    ImGui::PopStyleColor(count);
}

ZIMGUI_API void zimguiPushStyleVar1f(ImGuiStyleVar idx, float var) {
    ImGui::PushStyleVar(idx, var);
}

ZIMGUI_API void zimguiPushStyleVar2f(ImGuiStyleVar idx, const float var[2]) {
    ImGui::PushStyleVar(idx, { var[0], var[1] });
}

ZIMGUI_API void zimguiPopStyleVar(int count) {
    ImGui::PopStyleVar(count);
}

ZIMGUI_API void zimguiPushItemWidth(float item_width) {
    ImGui::PushItemWidth(item_width);
}

ZIMGUI_API void zimguiPopItemWidth(void) {
    ImGui::PopItemWidth();
}

ZIMGUI_API void zimguiSetNextItemWidth(float item_width) {
    ImGui::SetNextItemWidth(item_width);
}

ZIMGUI_API void zimguiSetItemDefaultFocus(void) {
    ImGui::SetItemDefaultFocus();
}

ZIMGUI_API ImFont* zimguiGetFont(void) {
    return ImGui::GetFont();
}

ZIMGUI_API float zimguiGetFontSize(void) {
    return ImGui::GetFontSize();
}

ZIMGUI_API void zimguiGetFontTexUvWhitePixel(float uv[2]) {
    const ImVec2 cs = ImGui::GetFontTexUvWhitePixel();
    uv[0] = cs[0];
    uv[1] = cs[1];
}

ZIMGUI_API void zimguiPushFont(ImFont* font) {
    ImGui::PushFont(font);
}

ZIMGUI_API void zimguiPopFont(void) {
    ImGui::PopFont();
}

ZIMGUI_API bool zimguiTreeNode(const char* label) {
    return ImGui::TreeNode(label);
}

ZIMGUI_API bool zimguiTreeNodeFlags(const char* label, ImGuiTreeNodeFlags flags) {
    return ImGui::TreeNodeEx(label, flags);
}

ZIMGUI_API bool zimguiTreeNodeStrId(const char* str_id, const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    const bool ret = ImGui::TreeNodeV(str_id, fmt, args);
    va_end(args);
    return ret;
}

ZIMGUI_API bool zimguiTreeNodeStrIdFlags(const char* str_id, ImGuiTreeNodeFlags flags, const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    const bool ret = ImGui::TreeNodeExV(str_id, flags, fmt, args);
    va_end(args);
    return ret;
}

ZIMGUI_API bool zimguiTreeNodePtrId(const void* ptr_id, const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    const bool ret = ImGui::TreeNodeV(ptr_id, fmt, args);
    va_end(args);
    return ret;
}

ZIMGUI_API bool zimguiTreeNodePtrIdFlags(const void* ptr_id, ImGuiTreeNodeFlags flags, const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    const bool ret = ImGui::TreeNodeExV(ptr_id, flags, fmt, args);
    va_end(args);
    return ret;
}

ZIMGUI_API bool zimguiCollapsingHeader(const char* label, ImGuiTreeNodeFlags flags) {
    return ImGui::CollapsingHeader(label, flags);
}

ZIMGUI_API bool zimguiCollapsingHeaderStatePtr(const char* label, bool* p_visible, ImGuiTreeNodeFlags flags) {
    return ImGui::CollapsingHeader(label, p_visible, flags);
}

ZIMGUI_API void zimguiSetNextItemOpen(bool is_open, ImGuiCond cond) {
    ImGui::SetNextItemOpen(is_open, cond);
}

ZIMGUI_API void zimguiTreePushStrId(const char* str_id) {
    ImGui::TreePush(str_id);
}

ZIMGUI_API void zimguiTreePushPtrId(const void* ptr_id) {
    ImGui::TreePush(ptr_id);
}

ZIMGUI_API void zimguiTreePop(void) {
    ImGui::TreePop();
}

ZIMGUI_API void zimguiPushStrId(const char* str_id_begin, const char* str_id_end) {
    ImGui::PushID(str_id_begin, str_id_end);
}

ZIMGUI_API void zimguiPushStrIdZ(const char* str_id) {
    ImGui::PushID(str_id);
}

ZIMGUI_API void zimguiPushPtrId(const void* ptr_id) {
    ImGui::PushID(ptr_id);
}

ZIMGUI_API void zimguiPushIntId(int int_id) {
    ImGui::PushID(int_id);
}

ZIMGUI_API void zimguiPopId(void) {
    ImGui::PopID();
}

ZIMGUI_API ImGuiID zimguiGetStrId(const char* str_id_begin, const char* str_id_end) {
    return ImGui::GetID(str_id_begin, str_id_end);
}

ZIMGUI_API ImGuiID zimguiGetStrIdZ(const char* str_id) {
    return ImGui::GetID(str_id);
}

ZIMGUI_API ImGuiID zimguiGetPtrId(const void* ptr_id) {
    return ImGui::GetID(ptr_id);
}

ZIMGUI_API void zimguiSetClipboardText(const char* text) {
    ImGui::SetClipboardText(text);
}

ZIMGUI_API const char* zimguiGetClipboardText(void) {
    return ImGui::GetClipboardText();
}

ZIMGUI_API ImFont* zimguiIoAddFontFromFileWithConfig(
    const char* filename,
    float size_pixels,
    const ImFontConfig* config,
    const ImWchar* ranges
) {
    return ImGui::GetIO().Fonts->AddFontFromFileTTF(filename, size_pixels, config, ranges);
}

ZIMGUI_API ImFont* zimguiIoAddFontFromFile(const char* filename, float size_pixels) {
    return ImGui::GetIO().Fonts->AddFontFromFileTTF(filename, size_pixels, nullptr, nullptr);
}

ZIMGUI_API ImFont* zimguiIoAddFontFromMemoryWithConfig(
    void* font_data,
    int font_size,
    float size_pixels,
    const ImFontConfig* config,
    const ImWchar* ranges
) {
    return ImGui::GetIO().Fonts->AddFontFromMemoryTTF(font_data, font_size, size_pixels, config, ranges);
}

ZIMGUI_API ImFont* zimguiIoAddFontFromMemory(void* font_data, int font_size, float size_pixels) {
    ImFontConfig config = ImFontConfig();
    config.FontDataOwnedByAtlas = false;
    return ImGui::GetIO().Fonts->AddFontFromMemoryTTF(font_data, font_size, size_pixels, &config, nullptr);
}

ZIMGUI_API ImFontConfig zimguiFontConfig_Init(void) {
    return ImFontConfig();
}

ZIMGUI_API ImFont* zimguiIoGetFont(unsigned int index) {
    return ImGui::GetIO().Fonts->Fonts[index];
}

ZIMGUI_API void zimguiIoSetDefaultFont(ImFont* font) {
    ImGui::GetIO().FontDefault = font;
}

ZIMGUI_API unsigned char *zimguiIoGetFontsTexDataAsRgba32(int *width, int *height) {
    unsigned char *font_pixels;
    int font_width, font_height;
    ImGui::GetIO().Fonts->GetTexDataAsRGBA32(&font_pixels, &font_width, &font_height);
    *width = font_width;
    *height = font_height;
    return font_pixels;
}

ZIMGUI_API void zimguiIoSetFontsTexId(ImTextureID id) {
    ImGui::GetIO().Fonts->TexID = id;
}

ZIMGUI_API ImTextureID zimguiIoGetFontsTexId(void) {
    return ImGui::GetIO().Fonts->TexID;
}

ZIMGUI_API void zimguiIoSetConfigWindowsMoveFromTitleBarOnly(bool enabled) {
    ImGui::GetIO().ConfigWindowsMoveFromTitleBarOnly = enabled;
}

ZIMGUI_API bool zimguiIoGetWantCaptureMouse(void) {
    return ImGui::GetIO().WantCaptureMouse;
}

ZIMGUI_API bool zimguiIoGetWantCaptureKeyboard(void) {
    return ImGui::GetIO().WantCaptureKeyboard;
}

ZIMGUI_API bool zimguiIoGetWantTextInput(void) {
    return ImGui::GetIO().WantTextInput;
}

ZIMGUI_API void zimguiIoSetIniFilename(const char* filename) {
    ImGui::GetIO().IniFilename = filename;
}

ZIMGUI_API void zimguiIoSetConfigFlags(ImGuiConfigFlags flags) {
    ImGui::GetIO().ConfigFlags = flags;
}

ZIMGUI_API void zimguiIoSetDisplaySize(float width, float height) {
    ImGui::GetIO().DisplaySize = { width, height };
}

ZIMGUI_API void zimguiIoGetDisplaySize(float size[2]) {
    const ImVec2 ds = ImGui::GetIO().DisplaySize;
    size[0] = ds[0];
    size[1] = ds[1];
}

ZIMGUI_API void zimguiIoSetDisplayFramebufferScale(float sx, float sy) {
    ImGui::GetIO().DisplayFramebufferScale = { sx, sy };
}

ZIMGUI_API void zimguiIoSetDeltaTime(float delta_time) {
    ImGui::GetIO().DeltaTime = delta_time;
}

ZIMGUI_API void zimguiIoAddFocusEvent(bool focused) {
    ImGui::GetIO().AddFocusEvent(focused);
}

ZIMGUI_API void zimguiIoAddMousePositionEvent(float x, float y) {
    ImGui::GetIO().AddMousePosEvent(x, y);
}

ZIMGUI_API void zimguiIoAddMouseButtonEvent(ImGuiMouseButton button, bool down) {
    ImGui::GetIO().AddMouseButtonEvent(button, down);
}

ZIMGUI_API void zimguiIoAddMouseWheelEvent(float x, float y) {
    ImGui::GetIO().AddMouseWheelEvent(x, y);
}

ZIMGUI_API void zimguiIoAddKeyEvent(ImGuiKey key, bool down) {
    ImGui::GetIO().AddKeyEvent(key, down);
}

ZIMGUI_API void zimguiIoAddInputCharactersUTF8(const char* utf8_chars) {
    ImGui::GetIO().AddInputCharactersUTF8(utf8_chars);
}

ZIMGUI_API void zimguiIoSetKeyEventNativeData(ImGuiKey key, int keycode, int scancode) {
    ImGui::GetIO().SetKeyEventNativeData(key, keycode, scancode);
}

ZIMGUI_API void zimguiIoAddCharacterEvent(unsigned int c) {
    ImGui::GetIO().AddInputCharacter(c);
}


ZIMGUI_API bool zimguiIsItemHovered(ImGuiHoveredFlags flags) {
    return ImGui::IsItemHovered(flags);
}

ZIMGUI_API bool zimguiIsItemActive(void) {
    return ImGui::IsItemActive();
}

ZIMGUI_API bool zimguiIsItemFocused(void) {
    return ImGui::IsItemFocused();
}

ZIMGUI_API bool zimguiIsItemClicked(ImGuiMouseButton mouse_button) {
    return ImGui::IsItemClicked(mouse_button);
}

ZIMGUI_API bool zimguiIsMouseDown(ImGuiMouseButton button) {
    return ImGui::IsMouseDown(button);
}

ZIMGUI_API bool zimguiIsMouseClicked(ImGuiMouseButton button) {
    return ImGui::IsMouseClicked(button);
}

ZIMGUI_API bool zimguiIsMouseDoubleClicked(ImGuiMouseButton button) {
    return ImGui::IsMouseDoubleClicked(button);
}

ZIMGUI_API bool zimguiIsItemVisible(void) {
    return ImGui::IsItemVisible();
}

ZIMGUI_API bool zimguiIsItemEdited(void) {
    return ImGui::IsItemEdited();
}

ZIMGUI_API bool zimguiIsItemActivated(void) {
    return ImGui::IsItemActivated();
}

ZIMGUI_API bool zimguiIsItemDeactivated(void) {
    return ImGui::IsItemDeactivated();
}

ZIMGUI_API bool zimguiIsItemDeactivatedAfterEdit(void) {
    return ImGui::IsItemDeactivatedAfterEdit();
}

ZIMGUI_API bool zimguiIsItemToggledOpen(void) {
    return ImGui::IsItemToggledOpen();
}

ZIMGUI_API bool zimguiIsAnyItemHovered(void) {
    return ImGui::IsAnyItemHovered();
}

ZIMGUI_API bool zimguiIsAnyItemActive(void) {
    return ImGui::IsAnyItemActive();
}

ZIMGUI_API bool zimguiIsAnyItemFocused(void) {
    return ImGui::IsAnyItemFocused();
}

ZIMGUI_API void zimguiGetContentRegionAvail(float pos[2]) {
    const ImVec2 p = ImGui::GetContentRegionAvail();
    pos[0] = p.x;
    pos[1] = p.y;
}

ZIMGUI_API void zimguiGetContentRegionMax(float pos[2]) {
    const ImVec2 p = ImGui::GetContentRegionMax();
    pos[0] = p.x;
    pos[1] = p.y;
}

ZIMGUI_API void zimguiGetWindowContentRegionMin(float pos[2]) {
    const ImVec2 p = ImGui::GetWindowContentRegionMin();
    pos[0] = p.x;
    pos[1] = p.y;
}

ZIMGUI_API void zimguiGetWindowContentRegionMax(float pos[2]) {
    const ImVec2 p = ImGui::GetWindowContentRegionMax();
    pos[0] = p.x;
    pos[1] = p.y;
}

ZIMGUI_API void zimguiPushTextWrapPos(float wrap_pos_x) {
    ImGui::PushTextWrapPos(wrap_pos_x);
}

ZIMGUI_API void zimguiPopTextWrapPos(void) {
    ImGui::PopTextWrapPos();
}

ZIMGUI_API bool zimguiBeginTabBar(const char* string, ImGuiTabBarFlags flags) {
    return ImGui::BeginTabBar(string, flags);
}

ZIMGUI_API bool zimguiBeginTabItem(const char* string, bool* p_open, ImGuiTabItemFlags flags) {
    return ImGui::BeginTabItem(string, p_open, flags);
}

ZIMGUI_API void zimguiEndTabItem(void) {
    ImGui::EndTabItem();
}

ZIMGUI_API void zimguiEndTabBar(void) {
    ImGui::EndTabBar();
}

ZIMGUI_API void zimguiSetTabItemClosed(const char* tab_or_docked_window_label) {
    ImGui::SetTabItemClosed(tab_or_docked_window_label);
}

ZIMGUI_API bool zimguiBeginMenuBar(void) {
    return ImGui::BeginMenuBar();
}

ZIMGUI_API void zimguiEndMenuBar(void) {
    ImGui::EndMenuBar();
}

ZIMGUI_API bool zimguiBeginMainMenuBar(void) {
    return ImGui::BeginMainMenuBar();
}

ZIMGUI_API void zimguiEndMainMenuBar(void) {
    ImGui::EndMainMenuBar();
}

ZIMGUI_API bool zimguiBeginMenu(const char* label, bool enabled) {
    return ImGui::BeginMenu(label, enabled);
}

ZIMGUI_API void zimguiEndMenu(void) {
    ImGui::EndMenu();
}

ZIMGUI_API bool zimguiMenuItem(const char* label, const char* shortcut, bool selected, bool enabled) {
    return ImGui::MenuItem(label, shortcut, selected, enabled);
}

ZIMGUI_API bool zimguiMenuItemPtr(const char* label, const char* shortcut, bool* selected, bool enabled) {
    return ImGui::MenuItem(label, shortcut, selected, enabled);
}

ZIMGUI_API bool zimguiBeginTooltip(void) {
    return ImGui::BeginTooltip();
}

ZIMGUI_API void zimguiEndTooltip(void) {
    ImGui::EndTooltip();
}

ZIMGUI_API bool zimguiBeginPopup(const char* str_id, ImGuiWindowFlags flags){
    return ImGui::BeginPopup(str_id, flags);
}

ZIMGUI_API bool zimguiBeginPopupContextWindow(void) {
    return ImGui::BeginPopupContextWindow();
}

ZIMGUI_API bool zimguiBeginPopupContextItem(void) {
    return ImGui::BeginPopupContextItem();
}

ZIMGUI_API bool zimguiBeginPopupModal(const char* name, bool* p_open, ImGuiWindowFlags flags) {
    return ImGui::BeginPopupModal(name, p_open, flags);
}

ZIMGUI_API void zimguiEndPopup(void) {
    ImGui::EndPopup();
}

ZIMGUI_API void zimguiOpenPopup(const char* str_id, ImGuiPopupFlags popup_flags) {
    ImGui::OpenPopup(str_id, popup_flags);
}

ZIMGUI_API void zimguiCloseCurrentPopup(void) {
    ImGui::CloseCurrentPopup();
}
//--------------------------------------------------------------------------------------------------
//
// Tables
//
//--------------------------------------------------------------------------------------------------
ZIMGUI_API bool zimguiBeginTable(
    const char* str_id,
    int column,
    ImGuiTableFlags flags,
    const float outer_size[2],
    float inner_width
) {
    return ImGui::BeginTable(str_id, column, flags, { outer_size[0], outer_size[1] }, inner_width);
}

ZIMGUI_API void zimguiEndTable(void) {
    ImGui::EndTable();
}

ZIMGUI_API void zimguiTableNextRow(ImGuiTableRowFlags row_flags, float min_row_height) {
    ImGui::TableNextRow(row_flags, min_row_height);
}

ZIMGUI_API bool zimguiTableNextColumn(void) {
    return ImGui::TableNextColumn();
}

ZIMGUI_API bool zimguiTableSetColumnIndex(int column_n) {
    return ImGui::TableSetColumnIndex(column_n);
}

ZIMGUI_API void zimguiTableSetupColumn(
    const char* label,
    ImGuiTableColumnFlags flags,
    float init_width_or_height,
    ImGuiID user_id
) {
    ImGui::TableSetupColumn(label, flags, init_width_or_height, user_id);
}

ZIMGUI_API void zimguiTableSetupScrollFreeze(int cols, int rows) {
    ImGui::TableSetupScrollFreeze(cols, rows);
}

ZIMGUI_API void zimguiTableHeadersRow(void) {
    ImGui::TableHeadersRow();
}

ZIMGUI_API void zimguiTableHeader(const char* label) {
    ImGui::TableHeader(label);
}

ZIMGUI_API ImGuiTableSortSpecs* zimguiTableGetSortSpecs(void) {
    return ImGui::TableGetSortSpecs();
}

ZIMGUI_API int zimguiTableGetColumnCount(void) {
    return ImGui::TableGetColumnCount();
}

ZIMGUI_API int zimguiTableGetColumnIndex(void) {
    return ImGui::TableGetColumnIndex();
}

ZIMGUI_API int zimguiTableGetRowIndex(void) {
    return ImGui::TableGetRowIndex();
}

ZIMGUI_API const char* zimguiTableGetColumnName(int column_n) {
    return ImGui::TableGetColumnName(column_n);
}

ZIMGUI_API ImGuiTableColumnFlags zimguiTableGetColumnFlags(int column_n) {
    return ImGui::TableGetColumnFlags(column_n);
}

ZIMGUI_API void zimguiTableSetColumnEnabled(int column_n, bool v) {
    ImGui::TableSetColumnEnabled(column_n, v);
}

ZIMGUI_API void zimguiTableSetBgColor(ImGuiTableBgTarget target, ImU32 color, int column_n) {
    ImGui::TableSetBgColor(target, color, column_n);
}
//--------------------------------------------------------------------------------------------------
//
// Color Utilities
//
//--------------------------------------------------------------------------------------------------
ZIMGUI_API void zimguiColorConvertU32ToFloat4(ImU32 in, float rgba[4]) {
    const ImVec4 c = ImGui::ColorConvertU32ToFloat4(in);
    rgba[0] = c.x;
    rgba[1] = c.y;
    rgba[2] = c.z;
    rgba[3] = c.w;
}

ZIMGUI_API ImU32 zimguiColorConvertFloat4ToU32(const float in[4]) {
    return ImGui::ColorConvertFloat4ToU32({ in[0], in[1], in[2], in[3] });
}

ZIMGUI_API void zimguiColorConvertRGBtoHSV(float r, float g, float b, float* out_h, float* out_s, float* out_v) {
    return ImGui::ColorConvertRGBtoHSV(r, g, b, *out_h, *out_s, *out_v);
}

ZIMGUI_API void zimguiColorConvertHSVtoRGB(float h, float s, float v, float* out_r, float* out_g, float* out_b) {
    return ImGui::ColorConvertHSVtoRGB(h, s, v, *out_r, *out_g, *out_b);
}
//--------------------------------------------------------------------------------------------------
//
// Inputs Utilities: Keyboard
//
//--------------------------------------------------------------------------------------------------
ZIMGUI_API bool zimguiIsKeyDown(ImGuiKey key) {
    return ImGui::IsKeyDown(key);
}
//--------------------------------------------------------------------------------------------------
//
// DrawList
//
//--------------------------------------------------------------------------------------------------
ZIMGUI_API ImDrawList *zimguiGetWindowDrawList(void) {
    return ImGui::GetWindowDrawList();
}

ZIMGUI_API ImDrawList *zimguiGetBackgroundDrawList(void) {
    return ImGui::GetBackgroundDrawList();
}

ZIMGUI_API ImDrawList *zimguiGetForegroundDrawList(void) {
    return ImGui::GetForegroundDrawList();
}

ZIMGUI_API ImDrawList *zimguiCreateDrawList(void) {
    return IM_NEW(ImDrawList)(ImGui::GetDrawListSharedData());
}

ZIMGUI_API void zimguiDestroyDrawList(ImDrawList *draw_list) {
  IM_DELETE(draw_list);
}

ZIMGUI_API const char *zimguiDrawList_GetOwnerName(ImDrawList *draw_list) {
    return draw_list->_OwnerName;
}

ZIMGUI_API void zimguiDrawList_ResetForNewFrame(ImDrawList *draw_list) {
    draw_list->_ResetForNewFrame();
}

ZIMGUI_API void zimguiDrawList_ClearFreeMemory(ImDrawList *draw_list) {
    draw_list->_ClearFreeMemory();
}

ZIMGUI_API int zimguiDrawList_GetVertexBufferLength(ImDrawList *draw_list) {
    return draw_list->VtxBuffer.size();
}
ZIMGUI_API ImDrawVert *zimguiDrawList_GetVertexBufferData(ImDrawList *draw_list) {
    return draw_list->VtxBuffer.begin();
}

ZIMGUI_API int zimguiDrawList_GetIndexBufferLength(ImDrawList *draw_list) {
    return draw_list->IdxBuffer.size();
}
ZIMGUI_API ImDrawIdx *zimguiDrawList_GetIndexBufferData(ImDrawList *draw_list) {
    return draw_list->IdxBuffer.begin();
}
ZIMGUI_API unsigned int zimguiDrawList_GetCurrentIndex(ImDrawList *draw_list) {
    return draw_list->_VtxCurrentIdx;
}

ZIMGUI_API int zimguiDrawList_GetCmdBufferLength(ImDrawList *draw_list) {
    return draw_list->CmdBuffer.size();
}
ZIMGUI_API ImDrawCmd *zimguiDrawList_GetCmdBufferData(ImDrawList *draw_list) {
    return draw_list->CmdBuffer.begin();
}

ZIMGUI_API void zimguiDrawList_SetFlags(ImDrawList *draw_list, ImDrawListFlags flags) {
    draw_list->Flags = flags;
}
ZIMGUI_API ImDrawListFlags zimguiDrawList_GetFlags(ImDrawList *draw_list) {
    return draw_list->Flags;
}

ZIMGUI_API void zimguiDrawList_PushClipRect(
    ImDrawList* draw_list,
    const float clip_rect_min[2],
    const float clip_rect_max[2],
    bool intersect_with_current_clip_rect
) {
    draw_list->PushClipRect(
        { clip_rect_min[0], clip_rect_min[1] },
        { clip_rect_max[0], clip_rect_max[1] },
        intersect_with_current_clip_rect
    );
}

ZIMGUI_API void zimguiDrawList_PushClipRectFullScreen(ImDrawList* draw_list) {
    draw_list->PushClipRectFullScreen();
}

ZIMGUI_API void zimguiDrawList_PopClipRect(ImDrawList* draw_list) {
    draw_list->PopClipRect();
}

ZIMGUI_API void zimguiDrawList_PushTextureId(ImDrawList* draw_list, ImTextureID texture_id) {
    draw_list->PushTextureID(texture_id);
}

ZIMGUI_API void zimguiDrawList_PopTextureId(ImDrawList* draw_list) {
    draw_list->PopTextureID();
}

ZIMGUI_API void zimguiDrawList_GetClipRectMin(ImDrawList* draw_list, float clip_min[2]) {
    const ImVec2 c = draw_list->GetClipRectMin();
    clip_min[0] = c.x;
    clip_min[1] = c.y;
}

ZIMGUI_API void zimguiDrawList_GetClipRectMax(ImDrawList* draw_list, float clip_max[2]) {
    const ImVec2 c = draw_list->GetClipRectMax();
    clip_max[0] = c.x;
    clip_max[1] = c.y;
}

ZIMGUI_API void zimguiDrawList_AddLine(
    ImDrawList* draw_list,
    const float p1[2],
    const float p2[2],
    ImU32 col,
    float thickness
) {
    draw_list->AddLine({ p1[0], p1[1] }, { p2[0], p2[1] }, col, thickness);
}

ZIMGUI_API void zimguiDrawList_AddRect(
    ImDrawList* draw_list,
    const float pmin[2],
    const float pmax[2],
    ImU32 col,
    float rounding,
    ImDrawFlags flags,
    float thickness
) {
    draw_list->AddRect({ pmin[0], pmin[1] }, { pmax[0], pmax[1] }, col, rounding, flags, thickness);
}

ZIMGUI_API void zimguiDrawList_AddRectFilled(
    ImDrawList* draw_list,
    const float pmin[2],
    const float pmax[2],
    ImU32 col,
    float rounding,
    ImDrawFlags flags
) {
    draw_list->AddRectFilled({ pmin[0], pmin[1] }, { pmax[0], pmax[1] }, col, rounding, flags);
}

ZIMGUI_API void zimguiDrawList_AddRectFilledMultiColor(
    ImDrawList* draw_list,
    const float pmin[2],
    const float pmax[2],
    ImU32 col_upr_left,
    ImU32 col_upr_right,
    ImU32 col_bot_right,
    ImU32 col_bot_left
) {
    draw_list->AddRectFilledMultiColor(
        { pmin[0], pmin[1] },
        { pmax[0], pmax[1] },
        col_upr_left,
        col_upr_right,
        col_bot_right,
        col_bot_left
    );
}

ZIMGUI_API void zimguiDrawList_AddQuad(
    ImDrawList* draw_list,
    const float p1[2],
    const float p2[2],
    const float p3[2],
    const float p4[2],
    ImU32 col,
    float thickness
) {
    draw_list->AddQuad({ p1[0], p1[1] }, { p2[0], p2[1] }, { p3[0], p3[1] }, { p4[0], p4[1] }, col, thickness);
}

ZIMGUI_API void zimguiDrawList_AddQuadFilled(
    ImDrawList* draw_list,
    const float p1[2],
    const float p2[2],
    const float p3[2],
    const float p4[2],
    ImU32 col
) {
    draw_list->AddQuadFilled({ p1[0], p1[1] }, { p2[0], p2[1] }, { p3[0], p3[1] }, { p4[0], p4[1] }, col);
}

ZIMGUI_API void zimguiDrawList_AddTriangle(
    ImDrawList* draw_list,
    const float p1[2],
    const float p2[2],
    const float p3[2],
    ImU32 col,
    float thickness
) {
    draw_list->AddTriangle({ p1[0], p1[1] }, { p2[0], p2[1] }, { p3[0], p3[1] }, col, thickness);
}

ZIMGUI_API void zimguiDrawList_AddTriangleFilled(
    ImDrawList* draw_list,
    const float p1[2],
    const float p2[2],
    const float p3[2],
    ImU32 col
) {
    draw_list->AddTriangleFilled({ p1[0], p1[1] }, { p2[0], p2[1] }, { p3[0], p3[1] }, col);
}

ZIMGUI_API void zimguiDrawList_AddCircle(
    ImDrawList* draw_list,
    const float center[2],
    float radius,
    ImU32 col,
    int num_segments,
    float thickness
) {
    draw_list->AddCircle({ center[0], center[1] }, radius, col, num_segments, thickness);
}

ZIMGUI_API void zimguiDrawList_AddCircleFilled(
    ImDrawList* draw_list,
    const float center[2],
    float radius,
    ImU32 col,
    int num_segments
) {
    draw_list->AddCircleFilled({ center[0], center[1] }, radius, col, num_segments);
}

ZIMGUI_API void zimguiDrawList_AddNgon(
    ImDrawList* draw_list,
    const float center[2],
    float radius,
    ImU32 col,
    int num_segments,
    float thickness
) {
    draw_list->AddNgon({ center[0], center[1] }, radius, col, num_segments, thickness);
}

ZIMGUI_API void zimguiDrawList_AddNgonFilled(
    ImDrawList* draw_list,
    const float center[2],
    float radius,
    ImU32 col,
    int num_segments
) {
    draw_list->AddNgonFilled({ center[0], center[1] }, radius, col, num_segments);
}

ZIMGUI_API void zimguiDrawList_AddText(
    ImDrawList* draw_list,
    const float pos[2],
    ImU32 col,
    const char* text_begin,
    const char* text_end
) {
    draw_list->AddText({ pos[0], pos[1] }, col, text_begin, text_end);
}

ZIMGUI_API void zimguiDrawList_AddPolyline(
    ImDrawList* draw_list,
    const float points[][2],
    int num_points,
    ImU32 col,
    ImDrawFlags flags,
    float thickness
) {
    draw_list->AddPolyline((const ImVec2*)&points[0][0], num_points, col, flags, thickness);
}

ZIMGUI_API void zimguiDrawList_AddConvexPolyFilled(
    ImDrawList* draw_list,
    const float points[][2],
    int num_points,
    ImU32 col
) {
    draw_list->AddConvexPolyFilled((const ImVec2*)&points[0][0], num_points, col);
}

ZIMGUI_API void zimguiDrawList_AddBezierCubic(
    ImDrawList* draw_list,
    const float p1[2],
    const float p2[2],
    const float p3[2],
    const float p4[2],
    ImU32 col,
    float thickness,
    int num_segments
) {
    draw_list->AddBezierCubic(
        { p1[0], p1[1] }, { p2[0], p2[1] }, { p3[0], p3[1] }, { p4[0], p4[1] }, col, thickness, num_segments
    );
}

ZIMGUI_API void zimguiDrawList_AddBezierQuadratic(
    ImDrawList* draw_list,
    const float p1[2],
    const float p2[2],
    const float p3[2],
    ImU32 col,
    float thickness,
    int num_segments
) {
    draw_list->AddBezierQuadratic(
        { p1[0], p1[1] }, { p2[0], p2[1] }, { p3[0], p3[1] }, col, thickness, num_segments
    );
}

ZIMGUI_API void zimguiDrawList_AddImage(
    ImDrawList* draw_list,
    ImTextureID user_texture_id,
    const float pmin[2],
    const float pmax[2],
    const float uvmin[2],
    const float uvmax[2],
    ImU32 col
) {
    draw_list->AddImage(
        user_texture_id,
        { pmin[0], pmin[1] },
        { pmax[0], pmax[1] },
        { uvmin[0], uvmin[1] },
        { uvmax[0], uvmax[1] },
        col
    );
}

ZIMGUI_API void zimguiDrawList_AddImageQuad(
    ImDrawList* draw_list,
    ImTextureID user_texture_id,
    const float p1[2],
    const float p2[2],
    const float p3[2],
    const float p4[2],
    const float uv1[2],
    const float uv2[2],
    const float uv3[2],
    const float uv4[2],
    ImU32 col
) {
    draw_list->AddImageQuad(
        user_texture_id,
        { p1[0], p1[1] },
        { p2[0], p2[1] },
        { p3[0], p3[1] },
        { p4[0], p4[1] },
        { uv1[0], uv1[1] },
        { uv2[0], uv2[1] },
        { uv3[0], uv3[1] },
        { uv4[0], uv4[1] },
        col
    );
}

ZIMGUI_API void zimguiDrawList_AddImageRounded(
    ImDrawList* draw_list,
    ImTextureID user_texture_id,
    const float pmin[2],
    const float pmax[2],
    const float uvmin[2],
    const float uvmax[2],
    ImU32 col,
    float rounding,
    ImDrawFlags flags
) {
    draw_list->AddImageRounded(
        user_texture_id,
        { pmin[0], pmin[1] },
        { pmax[0], pmax[1] },
        { uvmin[0], uvmin[1] },
        { uvmax[0], uvmax[1] },
        col,
        rounding,
        flags
    );
}

ZIMGUI_API void zimguiDrawList_PathClear(ImDrawList* draw_list) {
    draw_list->PathClear();
}

ZIMGUI_API void zimguiDrawList_PathLineTo(ImDrawList* draw_list, const float pos[2]) {
    draw_list->PathLineTo({ pos[0], pos[1] });
}

ZIMGUI_API void zimguiDrawList_PathLineToMergeDuplicate(ImDrawList* draw_list, const float pos[2]) {
    draw_list->PathLineToMergeDuplicate({ pos[0], pos[1] });
}

ZIMGUI_API void zimguiDrawList_PathFillConvex(ImDrawList* draw_list, ImU32 col) {
    draw_list->PathFillConvex(col);
}

ZIMGUI_API void zimguiDrawList_PathStroke(ImDrawList* draw_list, ImU32 col, ImDrawFlags flags, float thickness) {
    draw_list->PathStroke(col, flags, thickness);
}

ZIMGUI_API void zimguiDrawList_PathArcTo(
    ImDrawList* draw_list,
    const float center[2],
    float radius,
    float a_min,
    float a_max,
    int num_segments
) {
    draw_list->PathArcTo({ center[0], center[1] }, radius, a_min, a_max, num_segments);
}

ZIMGUI_API void zimguiDrawList_PathArcToFast(
    ImDrawList* draw_list,
    const float center[2],
    float radius,
    int a_min_of_12,
    int a_max_of_12
) {
    draw_list->PathArcToFast({ center[0], center[1] }, radius, a_min_of_12, a_max_of_12);
}

ZIMGUI_API void zimguiDrawList_PathBezierCubicCurveTo(
    ImDrawList* draw_list,
    const float p2[2],
    const float p3[2],
    const float p4[2],
    int num_segments
) {
    draw_list->PathBezierCubicCurveTo({ p2[0], p2[1] }, { p3[0], p3[1] }, { p4[0], p4[1] }, num_segments);
}

ZIMGUI_API void zimguiDrawList_PathBezierQuadraticCurveTo(
    ImDrawList* draw_list,
    const float p2[2],
    const float p3[2],
    int num_segments
) {
    draw_list->PathBezierQuadraticCurveTo({ p2[0], p2[1] }, { p3[0], p3[1] }, num_segments);
}

ZIMGUI_API void zimguiDrawList_PathRect(
    ImDrawList* draw_list,
    const float rect_min[2],
    const float rect_max[2],
    float rounding,
    ImDrawFlags flags
) {
    draw_list->PathRect({ rect_min[0], rect_min[1] }, { rect_max[0], rect_max[1] }, rounding, flags);
}

ZIMGUI_API void zimguiDrawList_PrimReserve( ImDrawList* draw_list, int idx_count, int vtx_count) {
    draw_list->PrimReserve(idx_count, vtx_count);
}

ZIMGUI_API void zimguiDrawList_PrimUnreserve( ImDrawList* draw_list, int idx_count, int vtx_count) {
    draw_list->PrimUnreserve(idx_count, vtx_count);
}

ZIMGUI_API void zimguiDrawList_PrimRect(
    ImDrawList* draw_list,
    const float a[2],
    const float b[2],
    ImU32 col
) {
    draw_list->PrimRect({ a[0], a[1] }, { b[0], b[1] }, col);
}

ZIMGUI_API void zimguiDrawList_PrimRectUV(
    ImDrawList* draw_list,
    const float a[2],
    const float b[2],
    const float uv_a[2],
    const float uv_b[2],
    ImU32 col
) {
    draw_list->PrimRectUV({ a[0], a[1] }, { b[0], b[1] }, { uv_a[0], uv_a[1] }, { uv_b[0], uv_b[1] }, col);
}

ZIMGUI_API void zimguiDrawList_PrimQuadUV(
    ImDrawList* draw_list,
    const float a[2],
    const float b[2],
    const float c[2],
    const float d[2],
    const float uv_a[2],
    const float uv_b[2],
    const float uv_c[2],
    const float uv_d[2],
    ImU32 col
) {
    draw_list->PrimQuadUV(
        { a[0], a[1] }, { b[0], b[1] }, { c[0], c[1] }, { d[0], d[1] },
        { uv_a[0], uv_a[1] }, { uv_b[0], uv_b[1] }, { uv_c[0], uv_c[1] }, { uv_d[0], uv_d[1] },
        col
    );
}

ZIMGUI_API void zimguiDrawList_PrimWriteVtx(
    ImDrawList* draw_list,
    const float pos[2],
    const float uv[2],
    ImU32 col
) {
    draw_list->PrimWriteVtx({ pos[0], pos[1] }, { uv[0], uv[1] }, col);
}

ZIMGUI_API void zimguiDrawList_PrimWriteIdx( ImDrawList* draw_list, ImDrawIdx idx) {
    draw_list->PrimWriteIdx(idx);
}

ZIMGUI_API void zimguiDrawList_AddCallback(ImDrawList* draw_list, ImDrawCallback callback, void* callback_data) {
    draw_list->AddCallback(callback, callback_data);
}

ZIMGUI_API void zimguiDrawList_AddResetRenderStateCallback(ImDrawList* draw_list) {
    draw_list->AddCallback(ImDrawCallback_ResetRenderState, NULL);
}
//--------------------------------------------------------------------------------------------------
//
// Viewport
//
//--------------------------------------------------------------------------------------------------
ZIMGUI_API ImGuiViewport* zimguiGetMainViewport(void) {
    return ImGui::GetMainViewport();
}

ZIMGUI_API void zimguiViewport_GetPos(ImGuiViewport* viewport, float p[2]) {
    const ImVec2 pos = viewport->Pos;
    p[0] = pos.x;
    p[1] = pos.y;
}

ZIMGUI_API void zimguiViewport_GetSize(ImGuiViewport* viewport, float p[2]) {
    const ImVec2 sz = viewport->Size;
    p[0] = sz.x;
    p[1] = sz.y;
}

ZIMGUI_API void zimguiViewport_GetWorkPos(ImGuiViewport* viewport, float p[2]) {
    const ImVec2 pos = viewport->WorkPos;
    p[0] = pos.x;
    p[1] = pos.y;
}

ZIMGUI_API void zimguiViewport_GetWorkSize(ImGuiViewport* viewport, float p[2]) {
    const ImVec2 sz = viewport->WorkSize;
    p[0] = sz.x;
    p[1] = sz.y;
}

//--------------------------------------------------------------------------------------------------
//
// Docking
//
//--------------------------------------------------------------------------------------------------
ZIMGUI_API ImGuiID zimguiDockSpace(const char* str_id, float size[2], ImGuiDockNodeFlags flags) {
    return ImGui::DockSpace(ImGui::GetID(str_id), {size[0], size[1]}, flags);
}

ZIMGUI_API ImGuiID zimguiDockSpaceOverViewport(const ImGuiViewport* viewport, ImGuiDockNodeFlags dockspace_flags) {
    return ImGui::DockSpaceOverViewport(viewport, dockspace_flags);
}


//--------------------------------------------------------------------------------------------------
//
// DockBuilder (Unstable internal imgui API, subject to change, use at own risk)
//
//--------------------------------------------------------------------------------------------------
ZIMGUI_API void zimguiDockBuilderDockWindow(const char* window_name, ImGuiID node_id) {
    ImGui::DockBuilderDockWindow(window_name, node_id);
}

ZIMGUI_API ImGuiID zimguiDockBuilderAddNode(ImGuiID node_id, ImGuiDockNodeFlags flags) {
    return ImGui::DockBuilderAddNode(node_id, flags);
}

ZIMGUI_API void zimguiDockBuilderRemoveNode(ImGuiID node_id) {
    ImGui::DockBuilderRemoveNode(node_id);
}

ZIMGUI_API void zimguiDockBuilderSetNodePos(ImGuiID node_id, float pos[2]) {
    ImGui::DockBuilderSetNodePos(node_id, {pos[0], pos[1]});
}

ZIMGUI_API void zimguiDockBuilderSetNodeSize(ImGuiID node_id, float size[2]) {
    ImGui::DockBuilderSetNodeSize(node_id, {size[0], size[1]});
}

ZIMGUI_API ImGuiID zimguiDockBuilderSplitNode(
    ImGuiID node_id,
    ImGuiDir split_dir,
    float size_ratio_for_node_at_dir,
    ImGuiID* out_id_at_dir,
    ImGuiID* out_id_at_opposite_dir
) {
    return ImGui::DockBuilderSplitNode(
        node_id,
        split_dir,
        size_ratio_for_node_at_dir,
        out_id_at_dir,
        out_id_at_opposite_dir
    );
}

ZIMGUI_API void zimguiDockBuilderFinish(ImGuiID node_id) {
    ImGui::DockBuilderFinish(node_id);
}


#if ZIMGUI_IMPLOT
//--------------------------------------------------------------------------------------------------
//
// ImPlot
//
//--------------------------------------------------------------------------------------------------
ZIMGUI_API ImPlotContext* zimguiPlot_CreateContext(void) {
    return ImPlot::CreateContext();
}

ZIMGUI_API void zimguiPlot_DestroyContext(ImPlotContext* ctx) {
    ImPlot::DestroyContext(ctx);
}

ZIMGUI_API ImPlotContext* zimguiPlot_GetCurrentContext(void) {
    return ImPlot::GetCurrentContext();
}

ZIMGUI_API ImPlotStyle zimguiPlotStyle_Init(void) {
    return ImPlotStyle();
}

ZIMGUI_API ImPlotStyle* zimguiPlot_GetStyle(void) {
    return &ImPlot::GetStyle();
}

ZIMGUI_API void zimguiPlot_PushStyleColor4f(ImPlotCol idx, const float col[4]) {
    ImPlot::PushStyleColor(idx, { col[0], col[1], col[2], col[3] });
}

ZIMGUI_API void zimguiPlot_PushStyleColor1u(ImPlotCol idx, ImU32 col) {
    ImPlot::PushStyleColor(idx, col);
}

ZIMGUI_API void zimguiPlot_PopStyleColor(int count) {
    ImPlot::PopStyleColor(count);
}

ZIMGUI_API void zimguiPlot_PushStyleVar1i(ImPlotStyleVar idx, int var) {
    ImPlot::PushStyleVar(idx, var);
}

ZIMGUI_API void zimguiPlot_PushStyleVar1f(ImPlotStyleVar idx, float var) {
    ImPlot::PushStyleVar(idx, var);
}

ZIMGUI_API void zimguiPlot_PushStyleVar2f(ImPlotStyleVar idx, const float var[2]) {
    ImPlot::PushStyleVar(idx, { var[0], var[1] });
}

ZIMGUI_API void zimguiPlot_PopStyleVar(int count) {
    ImPlot::PopStyleVar(count);
}

ZIMGUI_API void zimguiPlot_SetupLegend(ImPlotLocation location, ImPlotLegendFlags flags) {
    ImPlot::SetupLegend(location, flags);
}

ZIMGUI_API void zimguiPlot_SetupAxis(ImAxis axis, const char* label, ImPlotAxisFlags flags) {
    ImPlot::SetupAxis(axis, label, flags);
}

ZIMGUI_API void zimguiPlot_SetupAxisLimits(ImAxis axis, double v_min, double v_max, ImPlotCond cond) {
    ImPlot::SetupAxisLimits(axis, v_min, v_max, cond);
}

ZIMGUI_API void zimguiPlot_SetupFinish(void) {
    ImPlot::SetupFinish();
}

ZIMGUI_API bool zimguiPlot_BeginPlot(const char* title_id, float width, float height, ImPlotFlags flags) {
    return ImPlot::BeginPlot(title_id, { width, height }, flags);
}

ZIMGUI_API void zimguiPlot_PlotLineValues(
    const char* label_id,
    ImGuiDataType data_type,
    const void* values,
    int count,
    double xscale,
    double x0,
    ImPlotLineFlags flags,
    int offset,
    int stride
) {
    if (data_type == ImGuiDataType_S8)
        ImPlot::PlotLine(label_id, (const ImS8*)values, count, xscale, x0, flags, offset, stride);
    else if (data_type == ImGuiDataType_U8)
        ImPlot::PlotLine(label_id, (const ImU8*)values, count, xscale, x0, flags, offset, stride);
    else if (data_type == ImGuiDataType_S16)
        ImPlot::PlotLine(label_id, (const ImS16*)values, count, xscale, x0, flags, offset, stride);
    else if (data_type == ImGuiDataType_U16)
        ImPlot::PlotLine(label_id, (const ImU16*)values, count, xscale, x0, flags, offset, stride);
    else if (data_type == ImGuiDataType_S32)
        ImPlot::PlotLine(label_id, (const ImS32*)values, count, xscale, x0, flags, offset, stride);
    else if (data_type == ImGuiDataType_U32)
        ImPlot::PlotLine(label_id, (const ImU32*)values, count, xscale, x0, flags, offset, stride);
    else if (data_type == ImGuiDataType_Float)
        ImPlot::PlotLine(label_id, (const float*)values, count, xscale, x0, flags, offset, stride);
    else if (data_type == ImGuiDataType_Double)
        ImPlot::PlotLine(label_id, (const double*)values, count, xscale, x0, flags, offset, stride);
    else
        assert(false);
}

ZIMGUI_API void zimguiPlot_PlotLine(
    const char* label_id,
    ImGuiDataType data_type,
    const void* xv,
    const void* yv,
    int count,
    ImPlotLineFlags flags,
    int offset,
    int stride
) {
    if (data_type == ImGuiDataType_S8)
        ImPlot::PlotLine(label_id, (const ImS8*)xv, (const ImS8*)yv, count, flags, offset, stride);
    else if (data_type == ImGuiDataType_U8)
        ImPlot::PlotLine(label_id, (const ImU8*)xv, (const ImU8*)yv, count, flags, offset, stride);
    else if (data_type == ImGuiDataType_S16)
        ImPlot::PlotLine(label_id, (const ImS16*)xv, (const ImS16*)yv, count, flags, offset, stride);
    else if (data_type == ImGuiDataType_U16)
        ImPlot::PlotLine(label_id, (const ImU16*)xv, (const ImU16*)yv, count, flags, offset, stride);
    else if (data_type == ImGuiDataType_S32)
        ImPlot::PlotLine(label_id, (const ImS32*)xv, (const ImS32*)yv, count, flags, offset, stride);
    else if (data_type == ImGuiDataType_U32)
        ImPlot::PlotLine(label_id, (const ImU32*)xv, (const ImU32*)yv, count, flags, offset, stride);
    else if (data_type == ImGuiDataType_Float)
        ImPlot::PlotLine(label_id, (const float*)xv, (const float*)yv, count, flags, offset, stride);
    else if (data_type == ImGuiDataType_Double)
        ImPlot::PlotLine(label_id, (const double*)xv, (const double*)yv, count, flags, offset, stride);
    else
        assert(false);
}

ZIMGUI_API void zimguiPlot_PlotScatter(
    const char* label_id,
    ImGuiDataType data_type,
    const void* xv,
    const void* yv,
    int count,
    ImPlotScatterFlags flags,
    int offset,
    int stride
) {
    if (data_type == ImGuiDataType_S8)
        ImPlot::PlotScatter(label_id, (const ImS8*)xv, (const ImS8*)yv, count, flags, offset, stride);
    else if (data_type == ImGuiDataType_U8)
        ImPlot::PlotScatter(label_id, (const ImU8*)xv, (const ImU8*)yv, count, flags, offset, stride);
    else if (data_type == ImGuiDataType_S16)
        ImPlot::PlotScatter(label_id, (const ImS16*)xv, (const ImS16*)yv, count, flags, offset, stride);
    else if (data_type == ImGuiDataType_U16)
        ImPlot::PlotScatter(label_id, (const ImU16*)xv, (const ImU16*)yv, count, flags, offset, stride);
    else if (data_type == ImGuiDataType_S32)
        ImPlot::PlotScatter(label_id, (const ImS32*)xv, (const ImS32*)yv, count, flags, offset, stride);
    else if (data_type == ImGuiDataType_U32)
        ImPlot::PlotScatter(label_id, (const ImU32*)xv, (const ImU32*)yv, count, flags, offset, stride);
    else if (data_type == ImGuiDataType_Float)
        ImPlot::PlotScatter(label_id, (const float*)xv, (const float*)yv, count, flags, offset, stride);
    else if (data_type == ImGuiDataType_Double)
        ImPlot::PlotScatter(label_id, (const double*)xv, (const double*)yv, count, flags, offset, stride);
    else
        assert(false);
}

ZIMGUI_API void zimguiPlot_PlotScatterValues(
    const char* label_id,
    ImGuiDataType data_type,
    const void* values,
    int count,
    double xscale,
    double x0,
    ImPlotScatterFlags flags,
    int offset,
    int stride
) {
    if (data_type == ImGuiDataType_S8)
        ImPlot::PlotScatter(label_id, (const ImS8*)values, count, xscale, x0, flags, offset, stride);
    else if (data_type == ImGuiDataType_U8)
        ImPlot::PlotScatter(label_id, (const ImU8*)values, count, xscale, x0, flags, offset, stride);
    else if (data_type == ImGuiDataType_S16)
        ImPlot::PlotScatter(label_id, (const ImS16*)values, count, xscale, x0, flags, offset, stride);
    else if (data_type == ImGuiDataType_U16)
        ImPlot::PlotScatter(label_id, (const ImU16*)values, count, xscale, x0, flags, offset, stride);
    else if (data_type == ImGuiDataType_S32)
        ImPlot::PlotScatter(label_id, (const ImS32*)values, count, xscale, x0, flags, offset, stride);
    else if (data_type == ImGuiDataType_U32)
        ImPlot::PlotScatter(label_id, (const ImU32*)values, count, xscale, x0, flags, offset, stride);
    else if (data_type == ImGuiDataType_Float)
        ImPlot::PlotScatter(label_id, (const float*)values, count, xscale, x0, flags, offset, stride);
    else if (data_type == ImGuiDataType_Double)
        ImPlot::PlotScatter(label_id, (const double*)values, count, xscale, x0, flags, offset, stride);
    else
        assert(false);
}

ZIMGUI_API void zimguiPlot_PlotShaded(
    const char* label_id,
    ImGuiDataType data_type,
    const void* xv,
    const void* yv,
    int count,
    double yref,
    ImPlotShadedFlags flags,
    int offset,
    int stride
) {
    if (data_type == ImGuiDataType_S8)
        ImPlot::PlotShaded(label_id, (const ImS8*)xv, (const ImS8*)yv, count, yref, flags, offset, stride);
    else if (data_type == ImGuiDataType_U8)
        ImPlot::PlotShaded(label_id, (const ImU8*)xv, (const ImU8*)yv, count, yref, flags, offset, stride);
    else if (data_type == ImGuiDataType_S16)
        ImPlot::PlotShaded(label_id, (const ImS16*)xv, (const ImS16*)yv, count, yref, flags, offset, stride);
    else if (data_type == ImGuiDataType_U16)
        ImPlot::PlotShaded(label_id, (const ImU16*)xv, (const ImU16*)yv, count, yref, flags, offset, stride);
    else if (data_type == ImGuiDataType_S32)
        ImPlot::PlotShaded(label_id, (const ImS32*)xv, (const ImS32*)yv, count, yref, flags, offset, stride);
    else if (data_type == ImGuiDataType_U32)
        ImPlot::PlotShaded(label_id, (const ImU32*)xv, (const ImU32*)yv, count, yref, flags, offset, stride);
    else if (data_type == ImGuiDataType_Float)
        ImPlot::PlotShaded(label_id, (const float*)xv, (const float*)yv, count, yref, flags, offset, stride);
    else if (data_type == ImGuiDataType_Double)
        ImPlot::PlotShaded(label_id, (const double*)xv, (const double*)yv, count, yref, flags, offset, stride);
    else
        assert(false);
}

ZIMGUI_API void zimguiPlot_ShowDemoWindow(bool* p_open) {
    ImPlot::ShowDemoWindow(p_open);
}

ZIMGUI_API void zimguiPlot_EndPlot(void) {
    ImPlot::EndPlot();
}
ZIMGUI_API bool zimguiPlot_DragPoint(
        int id,
        double* x,
        double* y,
        float col[4],
        float size,
        ImPlotDragToolFlags flags
) {
    return ImPlot::DragPoint(
        id,
        x,
        y,
        (*(const ImVec4*)&(col[0])),
        size,
        flags
    );
}

ZIMGUI_API void zimguiPlot_PlotText(
        const char* text,
        double x, double y,
        const float pix_offset[2],
        ImPlotTextFlags flags=0
) {
    const ImVec2 p(pix_offset[0], pix_offset[1]);
    ImPlot::PlotText(text, x, y, p, flags);
}
#endif /* #ifdef ZIMGUI_IMPLOT */

//--------------------------------------------------------------------------------------------------
} /* extern "C" */


#if ZIMGUI_TE
//--------------------------------------------------------------------------------------------------
//
// ImGUI Test Engine
//
//--------------------------------------------------------------------------------------------------
extern "C"
{

    ZIMGUI_API void *zimguiTe_CreateContext(void)
    {
        ImGuiTestEngine *e = ImGuiTestEngine_CreateContext();

        ImGuiTestEngine_Start(e, ImGui::GetCurrentContext());
        ImGuiTestEngine_InstallDefaultCrashHandler();

        return e;
    }

    ZIMGUI_API void zimguiTe_DestroyContext(ImGuiTestEngine *engine)
    {
        ImGuiTestEngine_DestroyContext(engine);
    }

    ZIMGUI_API void zimguiTe_EngineSetRunSpeed(ImGuiTestEngine *engine, ImGuiTestRunSpeed speed)
    {
        ImGuiTestEngine_GetIO(engine).ConfigRunSpeed = speed;
    }

    ZIMGUI_API void zimguiTe_EngineExportJunitResult(ImGuiTestEngine *engine, const char *filename)
    {
        ImGuiTestEngine_GetIO(engine).ExportResultsFilename = filename;
        ImGuiTestEngine_GetIO(engine).ExportResultsFormat = ImGuiTestEngineExportFormat_JUnitXml;
    }

    ZIMGUI_API void zimguiTe_TryAbortEngine(ImGuiTestEngine *engine)
    {
        ImGuiTestEngine_TryAbortEngine(engine);
    }

    ZIMGUI_API void zimguiTe_Stop(ImGuiTestEngine *engine)
    {
        ImGuiTestEngine_Stop(engine);
    }

    ZIMGUI_API void zimguiTe_PostSwap(ImGuiTestEngine *engine)
    {
        ImGuiTestEngine_PostSwap(engine);
    }

    ZIMGUI_API bool zimguiTe_IsTestQueueEmpty(ImGuiTestEngine *engine)
    {
        return ImGuiTestEngine_IsTestQueueEmpty(engine);
    }

    ZIMGUI_API void zimguiTe_GetResult(ImGuiTestEngine *engine, int *count_tested, int *count_success)
    {
        int ct = 0;
        int cs = 0;
        ImGuiTestEngine_GetResult(engine, ct, cs);
        *count_tested = ct;
        *count_success = cs;
    }

    ZIMGUI_API void zimguiTe_PrintResultSummary(ImGuiTestEngine *engine)
    {
        ImGuiTestEngine_PrintResultSummary(engine);
    }

    ZIMGUI_API void zimguiTe_QueueTests(ImGuiTestEngine *engine, ImGuiTestGroup group, const char *filter_str, ImGuiTestRunFlags run_flags)
    {
        ImGuiTestEngine_QueueTests(engine, group, filter_str, run_flags);
    }

    ZIMGUI_API void zimguiTe_ShowTestEngineWindows(ImGuiTestEngine *engine, bool *p_open)
    {
        ImGuiTestEngine_ShowTestEngineWindows(engine, p_open);
    }

    ZIMGUI_API void *zimguiTe_RegisterTest(ImGuiTestEngine *engine, const char *category, const char *name, const char *src_file, int src_line, ImGuiTestGuiFunc *gui_fce, ImGuiTestTestFunc *gui_test_fce)
    {
        auto t = ImGuiTestEngine_RegisterTest(engine, category, name, src_file, src_line);
        t->GuiFunc = gui_fce;
        t->TestFunc = gui_test_fce;
        return t;
    }

    ZIMGUI_API bool zimguiTe_Check(const char *file, const char *func, int line, ImGuiTestCheckFlags flags, bool result, const char *expr)
    {
        return ImGuiTestEngine_Check(file, func, line, flags, result, expr);
    }

    // CONTEXT

    ZIMGUI_API void zimguiTe_ContextSetRef(ImGuiTestContext *ctx, const char *ref)
    {
        ctx->SetRef(ref);
    }

    ZIMGUI_API void zimguiTe_ContextWindowFocus(ImGuiTestContext *ctx, const char *ref)
    {
        ctx->WindowFocus(ref);
    }

    ZIMGUI_API void zimguiTe_ContextItemAction(ImGuiTestContext *ctx, ImGuiTestAction action, const char *ref, ImGuiTestOpFlags flags = 0, void *action_arg = NULL)
    {
        ctx->ItemAction(action, ref, flags, action_arg);
    }

    ZIMGUI_API void zimguiTe_ContextItemInputStrValue(ImGuiTestContext *ctx, const char *ref, const char *value)
    {
        ctx->ItemInputValue(ref, value);
    }

    ZIMGUI_API void zimguiTe_ContextItemInputIntValue(ImGuiTestContext *ctx, const char *ref, int value)
    {
        ctx->ItemInputValue(ref, value);
    }

    ZIMGUI_API void zimguiTe_ContextItemInputFloatValue(ImGuiTestContext *ctx, const char *ref, float value)
    {
        ctx->ItemInputValue(ref, value);
    }

    ZIMGUI_API void zimguiTe_ContextYield(ImGuiTestContext *ctx, int frame_count)
    {
        ctx->Yield(frame_count);
    }

    ZIMGUI_API void zimguiTe_ContextMenuAction(ImGuiTestContext *ctx, ImGuiTestAction action, const char *ref)
    {
        ctx->MenuAction(action, ref);
    }

    ZIMGUI_API void zimguiTe_ContextDragAndDrop(ImGuiTestContext *ctx, const char *ref_src, const char *ref_dst, ImGuiMouseButton button)
    {
        ctx->ItemDragAndDrop(ref_src, ref_dst, button);
    }

    ZIMGUI_API void zimguiTe_ContextKeyDown(ImGuiTestContext *ctx, ImGuiKeyChord key_chord)
    {
        ctx->KeyDown(key_chord);
    }

    ZIMGUI_API void zimguiTe_ContextKeyUp(ImGuiTestContext *ctx, ImGuiKeyChord key_chord)
    {
        ctx->KeyUp(key_chord);
    }

} /* extern "C" */
#endif