# Better Blur DX

Better Blur DX is a continuation of [Better Blur](https://github.com/taj-ny/kwin-effects-forceblur/) - a fork of the Plasma 6 blur effect with additional features and bug fixes.

![image](https://github.com/user-attachments/assets/f8a7c618-89b4-485a-b0f8-29dd5f77e3ca)

## Features

- X11 and Wayland support
- Force blur for arbitrary windows
- Adjust blur brightness, contrast, and saturation
- Configurable corner radius for rounded blur

This project focuses on bringing KWin blur to arbitrary windows and nothing else.
For more features, check out other projects or feel free to fork and create your own.

## Bug Fixes

Fixes for blur-related Plasma bugs that haven't been patched upstream:

- Blur may sometimes disappear during animations
- [Transparent color schemes don't work properly with the Breeze application style](https://github.com/taj-ny/kwin-effects-forceblur/pull/38)

## Supported Versions

Better Blur DX should work on the current stable version of Plasma.
Older versions aren't tested and may or may not work.

**Currently supported: Plasma 6.4+**

## Installation

> [!IMPORTANT]
> If the effect stops working after a system upgrade, you will need to rebuild it or reinstall the package.

### NixOS (Flakes)

```nix
# flake.nix
{
  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
    kwin-effects-better-blur-dx = {
      url = "github:xarblu/kwin-effects-better-blur-dx";
      inputs.nixpkgs.follows = "nixpkgs";
    };
  };
}
```

```nix
# configuration.nix
{ inputs, pkgs, ... }:
{
  environment.systemPackages = [
    inputs.kwin-effects-better-blur-dx.packages.${pkgs.system}.default # Wayland
    inputs.kwin-effects-better-blur-dx.packages.${pkgs.system}.x11     # X11
  ];
}
```

### Manual Build

#### Dependencies

- CMake
- Extra CMake Modules
- Plasma 6.4+
- Qt 6
- KF6
- KWin development packages

<details>
<summary>Arch Linux</summary>

**Wayland:**
```sh
sudo pacman -S base-devel git extra-cmake-modules qt6-tools kwin
```

**X11:**
```sh
sudo pacman -S base-devel git extra-cmake-modules qt6-tools kwin-x11
```
</details>

<details>
<summary>Debian/Ubuntu (KDE Neon, Kubuntu)</summary>

**Wayland:**
```sh
sudo apt install -y git cmake g++ extra-cmake-modules qt6-tools-dev kwin-dev \
    libkf6configwidgets-dev gettext libkf6crash-dev libkf6globalaccel-dev \
    libkf6kio-dev libkf6service-dev libkf6notifications-dev libkf6kcmutils-dev \
    libkdecorations3-dev libxcb-composite0-dev libxcb-randr0-dev libxcb-shm0-dev
```

**X11:**
```sh
sudo apt install -y git cmake g++ extra-cmake-modules qt6-tools-dev kwin-x11-dev \
    libkf6configwidgets-dev gettext libkf6crash-dev libkf6globalaccel-dev \
    libkf6kio-dev libkf6service-dev libkf6notifications-dev libkf6kcmutils-dev \
    libkdecorations3-dev libxcb-composite0-dev libxcb-randr0-dev libxcb-shm0-dev
```
</details>

<details>
<summary>Fedora 41+</summary>

**Wayland:**
```sh
sudo dnf -y install git cmake extra-cmake-modules gcc-g++ kf6-kwindowsystem-devel \
    plasma-workspace-devel libplasma-devel qt6-qtbase-private-devel qt6-qtbase-devel \
    kwin-devel kf6-knotifications-devel kf6-kio-devel kf6-kcrash-devel kf6-ki18n-devel \
    kf6-kguiaddons-devel libepoxy-devel kf6-kglobalaccel-devel kf6-kcmutils-devel \
    kf6-kconfigwidgets-devel kf6-kdeclarative-devel kdecoration-devel wayland-devel libdrm-devel
```

**X11:**
```sh
sudo dnf -y install git cmake extra-cmake-modules gcc-g++ kf6-kwindowsystem-devel \
    plasma-workspace-devel libplasma-devel qt6-qtbase-private-devel qt6-qtbase-devel \
    kf6-knotifications-devel kf6-kio-devel kf6-kcrash-devel kf6-ki18n-devel \
    kf6-kguiaddons-devel libepoxy-devel kf6-kglobalaccel-devel kf6-kcmutils-devel \
    kf6-kconfigwidgets-devel kf6-kdeclarative-devel kdecoration-devel wayland-devel \
    libdrm-devel kwin-x11-devel
```
</details>

<details>
<summary>openSUSE</summary>

**Wayland:**
```sh
sudo zypper in -y git cmake-full gcc-c++ kf6-extra-cmake-modules kcoreaddons-devel \
    kguiaddons-devel kconfigwidgets-devel kwindowsystem-devel ki18n-devel kiconthemes-devel \
    kpackage-devel frameworkintegration-devel kcmutils-devel kirigami2-devel \
    "cmake(KF6Config)" "cmake(KF6CoreAddons)" "cmake(KF6FrameworkIntegration)" \
    "cmake(KF6GuiAddons)" "cmake(KF6I18n)" "cmake(KF6KCMUtils)" "cmake(KF6KirigamiPlatform)" \
    "cmake(KF6WindowSystem)" "cmake(Qt6Core)" "cmake(Qt6DBus)" "cmake(Qt6Quick)" \
    "cmake(Qt6Svg)" "cmake(Qt6Widgets)" "cmake(Qt6Xml)" "cmake(Qt6UiTools)" \
    "cmake(KF6Crash)" "cmake(KF6GlobalAccel)" "cmake(KF6KIO)" "cmake(KF6Service)" \
    "cmake(KF6Notifications)" libepoxy-devel kwin6-devel
```

**X11:**
```sh
sudo zypper in -y git cmake-full gcc-c++ kf6-extra-cmake-modules kcoreaddons-devel \
    kguiaddons-devel kconfigwidgets-devel kwindowsystem-devel ki18n-devel kiconthemes-devel \
    kpackage-devel frameworkintegration-devel kcmutils-devel kirigami2-devel \
    "cmake(KF6Config)" "cmake(KF6CoreAddons)" "cmake(KF6FrameworkIntegration)" \
    "cmake(KF6GuiAddons)" "cmake(KF6I18n)" "cmake(KF6KCMUtils)" "cmake(KF6KirigamiPlatform)" \
    "cmake(KF6WindowSystem)" "cmake(Qt6Core)" "cmake(Qt6DBus)" "cmake(Qt6Quick)" \
    "cmake(Qt6Svg)" "cmake(Qt6Widgets)" "cmake(Qt6Xml)" "cmake(Qt6UiTools)" \
    "cmake(KF6Crash)" "cmake(KF6GlobalAccel)" "cmake(KF6KIO)" "cmake(KF6Service)" \
    "cmake(KF6Notifications)" libepoxy-devel kwin6-x11-devel
```
</details>

#### Building

```sh
git clone https://github.com/xarblu/kwin-effects-better-blur-dx
cd kwin-effects-better-blur-dx
mkdir build && cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/usr
make -j$(nproc)
sudo make install
```

For X11 builds, add `-DBETTERBLUR_X11=ON` to the cmake command.

> [!NOTE]
> Remove the `build` directory when rebuilding the effect.

<details>
<summary>Building on Fedora Kinoite</summary>

```sh
# Inside a toolbox container:
git clone https://github.com/xarblu/kwin-effects-better-blur-dx
cd kwin-effects-better-blur-dx
mkdir build && cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/usr
make -j$(nproc)
cpack -V -G RPM
exit
# On host:
sudo rpm-ostree install kwin-effects-better-blur-dx/build/kwin-better-blur-dx.rpm
```
</details>

## Usage

This effect conflicts with the default KWin blur effect (and other blur replacements).

1. Install the plugin
2. Open *System Settings* → *Desktop Effects*
3. Disable any existing blur effects
4. Enable *Better Blur DX*

### Making Windows Transparent

For blur to be visible, the window needs transparency. Options include:

- Use a transparent theme for the application
- Use a transparent color scheme like [Alpha](https://store.kde.org/p/1972214)
- Create a window rule that reduces window opacity

### Finding Window Classes

To specify windows for force blur, you need their window class. Find it by:

1. Run: `qdbus org.kde.KWin /KWin org.kde.KWin.queryWindowInfo`
2. Click on the window
3. Use either `resourceClass` or `resourceName`

Or: Right-click titlebar → *More Options* → *Configure Special Window/Application Settings* → *Window class (application)*

## Known Issues

### Effect Incompatibilities

- **KWin "Blur"** - Don't use both effects simultaneously; windows may get double-blurred
- **"Wobbly Windows"** - Blur may bleed outside deformed windows or be skipped during wobble animations

### High Cursor Latency on Wayland

Heavy blur with many windows can cause cursor lag on Wayland. Try these environment variables:

```sh
KWIN_DRM_NO_AMS=1
KWIN_FORCE_SW_CURSOR=0  # or =1
```

Intel GPUs use software cursor by default due to [this bug](https://gitlab.freedesktop.org/drm/intel/-/issues/9571).

## Credits

- [a-parhom/LightlyShaders](https://github.com/a-parhom/LightlyShaders) - CMakeLists.txt reference
- [taj-ny/kwin-effects-forceblur](https://github.com/taj-ny/kwin-effects-forceblur) - Original Better Blur

## License

GPL-3.0-or-later
