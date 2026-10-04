#!/usr/bin/env Rscript

comment <- "
Background

In 1796, 18-year-old Carl Friedrich Gauss proved that a regular heptadecagon can be constructed with compass and straightedge — the first such discovery in over 2,000 years. The stonemason tasked with his tombstone refused to carve a heptadecagon (\"nobody could tell it from a circle\") and made a 17-pointed star instead. This {17/8} heptadecagram adorns the monument of Gauss in Brunswick (Germany):

https://upload.wikimedia.org/wikipedia/commons/thumb/0/04/Braunschweig_Gauss-Denkmal_17-eckiger_Stern.jpg/330px-Braunschweig_Gauss-Denkmal_17-eckiger_Stern.jpg

CC-BY-SA, Benutzer:Brunswyk on de.wikipedia.org

Challenge

Draw the Gauss star with:

Gold/yellow fill (no internal edges visible)
Black outline
Specifications

Geometry: The 17 outer vertices lie on a circle, connected as a {17/8} star polygon:

vertex[i] = (cos(2π·8i/17), sin(2π·8i/17)) for i = 0..16

Equivalently, construct a 34-vertex boundary polygon alternating between outer radius R and inner radius r ≈ 0.337R, with tolerance r/R ∈ [1/2, 1/3].

Fill: The entire star interior must be filled — no crossing lines or holes visible.

Colors:

Fill: Hue between 45° and 65° (gold to yellow range), saturation ≥ 80%, lightness ≥ 50%
Stroke: Black or near-black (lightness ≤ 20%)
Size: Minimum 200×200 pixels, star reasonably centered.

Rotation: Any orientation is acceptable.

Rules

Compute vertices using language built-ins only — no geometry/polygon libraries
Standard graphics libraries (Canvas, SVG, PIL, etc.) allowed for rendering
Output: displayed graphic, image file, or valid SVG
Scoring

[code-golf] — shortest code in bytes wins.

Reference

Target output:
https://i.sstatic.net/A7mNpw8J.png


Gold (#FFD700) fill, black outline, {17/8} star polygon with winding fill.

The monument photo is shown in the Background section for historical context.

"

# ported from @test qa solution
symbols(0, st=t(rep(c(1, 3), 17)), bg=7)

