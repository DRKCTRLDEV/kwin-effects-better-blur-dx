#!/bin/sh
#
# Launches a nested Plasma X11 or Wayland session with virtual screens.
# Useful for testing the blur effect without affecting your main session.
#
# Usage: ./plasma-nested.sh [x11|wayland]

set -e

WIDTH=1920
HEIGHT=1080

DIR=/tmp/kwin-better-blur-dx

if [ ! -d "$DIR" ]; then
    mkdir -p "$DIR/.local/share"
    cp -r ~/.config "$DIR"
    cp -r ~/.local/share/konsole/ "$DIR/.local/share" 2>/dev/null || true

    # Remove settings that interfere with testing
    rm -f "$DIR/.config/kwinrc" "$DIR/.config/breezerc"
fi

if [ "$1" = "x11" ]; then
    SCREEN1="960/0x540/0+0+0 default"
    SCREEN2="960/0x500/0+960+40 none"
    SCREEN3="1500/0x540/0+210+540 none"

    unset XDG_SESSION_TYPE
    unset WAYLAND_DISPLAY

    Xephyr -screen "${WIDTH}x${HEIGHT}" +extension randr +extension glx +xinerama \
           +extension render +extension damage +extension xvideo +extension composite -ac :9 &

    LAUNCH_CMD="dbus-run-session /bin/sh -c \"
        DISPLAY=:9
        HOME=$DIR
        kwin_x11 &
        sleep 1
        xrandr --setmonitor A $SCREEN1
        xrandr --setmonitor B $SCREEN2
        xrandr --setmonitor C $SCREEN3
        plasmashell > /dev/null 2>&1
    \""
elif [ "$1" = "wayland" ]; then
    LAUNCH_CMD="HOME=$DIR dbus-run-session kwin_wayland --output-count 2 --width 960 --height 960 -- /bin/sh -c 'plasmashell' > /dev/null 2>&1"
else
    echo "Usage: $0 [x11|wayland]"
    exit 1
fi

if [ -f /etc/machine-id ]; then
    # NixOS
    nix shell . --command /bin/sh -c "$LAUNCH_CMD"
else
    eval "$LAUNCH_CMD"
fi