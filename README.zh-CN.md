# wxButtonLighterDarker

简体中文 | [English](README.md)

`wxButtonLighterDarker` 是一个基于 `wxWidgets` 的 Windows 桌面示例程序，主要用于演示按钮在悬停状态下如何根据背景色自动切换“变亮 / 变暗”效果。该项目同时支持实时调整按钮背景色、前景色以及明暗判定阈值，用于验证 `wxWidgets` 相关问题 [`#26453`](https://github.com/wxWidgets/wxWidgets/issues/26453)。

## 功能

- 实时调整按钮背景色与前景色（RGB 三个通道）
- 通过滑块或输入框同步修改颜色数值
- 在“灰度模式”和“亮度模式”之间切换
- 设置悬停时按钮颜色的变化方向
- 调整悬停时的颜色变化幅度
- 一键恢复默认背景色、前景色和判定参数

## 运行截图

### 主界面

![DemoMainInterface](assets/DemoMainInterface.jpg)

### 动态效果

![ProgramEffect](assets/ProgramEffect.gif)

## 界面说明

程序启动后会显示一个演示窗口，核心区域包括：

- **测试按钮**：用于观察当前按钮颜色以及悬停效果
- **背景色设置**：控制按钮背景色的 RGB 值，并显示背景灰度与亮度结果
- **前景色设置**：控制按钮文字颜色的 RGB 值
- **模式选择**：在灰度判定与亮度判定之间切换
- **阈值与变化量**：设置悬停时变亮 / 变暗的判断阈值与变化强度

## 工作原理

项目会根据当前背景色计算两个基础指标：

- **灰度值**：用于灰度模式下的明暗判断
- **亮度值**：用于亮度模式下的明暗判断

随后结合用户选择的“变亮 / 变暗”策略，在按钮进入 hot 状态时动态生成对应的悬停背景色。

## 项目结构

```text
wxButtonLighterDarker/
├─ wxButtonLighterDarker/        # Visual Studio 项目源码目录
│  ├─ wxButtonLighterDarker.cpp  # 应用程序入口
│  ├─ wxButtonLighterDarker.h    # 应用程序类声明
│  ├─ Window_FrameDemo.cpp/.h    # 主窗口逻辑、事件处理与按钮 Hot state 颜色计算
│  ├─ WxUIBase.cpp/.h            # wxFormBuilder 生成的界面基类
│  ├─ wxTestButton.h             # 自定义测试按钮控件，继承自 wxButton
│  ├─ stdafx.cpp/.h              # 预编译头文件
│  ├─ targetver.h                # Windows SDK 版本定义
│  └─ resource.h                 # 资源标识定义
├─ assets/                       # 运行截图与演示素材
├─ include/                      # wxWidgets 头文件
├─ lib/                          # wxWidgets 库文件
├─ wxButtonLighterDarker.sln     # Visual Studio 解决方案
└─ README.md
```

## 构建环境

- **操作系统**：Windows 10
- **开发工具**：Visual Studio 2022
- **GUI 框架**：wxWidgets 3.3.3（基于 master 提交 `ddd2b3f`）
- **库类型**：静态库
- **运行时**：静态运行时（`/MT`、`/MTd`）

### wxWidgets 构建说明

本项目依赖的 wxWidgets 在构建时做了如下定制：

- 在 `CMAKE_CXX_FLAGS_RELEASE` 中添加 `/MT`
- 在 `CMAKE_CXX_FLAGS_DEBUG` 中添加 `/MTd`
- 关闭 `wxBUILD_SHARED`，改为构建静态库
- 勾选 `wxBUILD_USE_STATIC_RUNTIME`，使用静态运行时

构建完成后：

- `include` 目录放置在项目根目录下的 `include/` 中
- `lib` 目录放置在项目根目录下的 `lib/` 中（由于体积较大，未上传到 GitHub 仓库）

## 构建步骤

1. 使用 Visual Studio 2022 打开 `wxButtonLighterDarker.sln`
2. 选择需要的配置，例如 `Debug` 或 `Release`
3. 选择平台，例如 `Win32` 或 `x64`
4. 编译并运行项目

如果你不想自行构建，也可以下载编译好的 Releases 文件进行测试（仅 MSW 平台）。

## 如何修改按钮变色逻辑

按钮悬停时的颜色变化逻辑主要集中在 `wxButtonLighterDarker/Window_FrameDemo.cpp` 的 `UpdateButtonUI()` 中。如果你想调整变色规则，可以重点修改下面几个部分。

### 1. 背景色和前景色读取

当前通过 `m_slider_background_*` 和 `m_slider_foreground_*` 获取 RGB 值。
如果希望支持更多颜色输入方式，可以在这里扩展数据来源。

### 2. 明暗判断方式

- 灰度模式使用 `RGB2GRAY(r, g, b)` 计算灰度值
- 亮度模式使用 `GetLightness(r, g, b)` 计算亮度值

如果需要更贴近人眼感知，可以替换为 HSV、HSL，或者 WCAG 对比度算法。

### 3. 阈值判断

- `m_gray_range` 和 `m_lightness_range` 分别是灰度模式和亮度模式的分界阈值
- 当前逻辑会根据背景颜色是否高于阈值，决定按钮在 hot 状态下是变亮还是变暗

### 4. 变化幅度

- `m_change_val` 控制悬停时颜色变化的强度
- 具体变化通过 `wxColour::ChangeLightness(100 ± m_change_val)` 实现

如果想让效果更柔和，可以缩小该值，或者改成自定义插值算法。

### 5. 默认值按钮

相关默认值分别在 `EventButtonClickBackgroundDef()`、`EventButtonClickForegroundDef()` 和 `EventButtonClickLdDef()` 中设置。
如果你修改了参数范围或界面逻辑，记得同步更新这些默认值。

如果你还想进一步扩展，比如增加渐变动画、按下状态单独配色，或者根据系统主题自动适配，也可以继续在 `UpdateButtonUI()` 的基础上实现。
