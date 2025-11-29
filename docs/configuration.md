# Configuration Guide

## General Settings

### Blur Strength
Controls the intensity of the blur effect. Higher values produce a more pronounced blur.

### Noise Strength
Adds dithering noise to reduce color banding artifacts in the blurred image.

### Window Opacity Affects Blur
Since Plasma 6, window opacity affects blur opacity. When enabled (default), transparent windows show less blur.

### Brightness / Saturation / Contrast
Adjust the visual appearance of the blurred area behind windows.

### Corner Radius
Applies rounded corners to the blur region. Set to 0 to disable.

## Force Blur

### Window Classes
Specify window classes (one per line) to apply force blur. Use `$blank` to match empty window classes, and `$$` for a literal dollar sign.

### Matching Mode
- **Blur only matching**: Only blur windows whose class matches the list
- **Blur all except matching**: Blur all windows except those in the list

### Blur Window Decorations
When enabled, blurs window decorations including borders. Useful for decorations that don't natively support blur or when you want rounded top corners.

### Blur Menus
Enable blur for dropdown menus, context menus, and popup windows.

### Blur Docks
Enable blur for dock/panel windows.
