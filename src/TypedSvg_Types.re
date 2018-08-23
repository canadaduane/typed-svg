module Utils = TypedSvg_Utils;

/**
 * Helper Types and Functions
 */
type commonAttr = {
  auto: string,
  inherit_: string,
  none: string,
};

let commonAttr = {auto: "auto", inherit_: "inherit", none: "none"};

/* In a future version of TypedSvg, this may be turned into a DSL */
type clockValue = string;

[@bs.deriving accessors]
type length =
  | Num(float)
  | Percent(float)
  | Px(float)
  | Cm(float)
  | Em(float)
  | Ex(float)
  | Inch(float)
  | Mm(float)
  | Pc(float)
  | Pt(float);

let lengthToString = value =>
  switch (value) {
  | Num(x) => Js.Float.toString(x)
  | Percent(x) => Js.Float.toString(x) ++ "%"
  | Px(x) => Js.Float.toString(x) ++ "px"
  | Cm(x) => Js.Float.toString(x) ++ "cm"
  | Em(x) => Js.Float.toString(x) ++ "em"
  | Ex(x) => Js.Float.toString(x) ++ "ex"
  | Inch(x) => Js.Float.toString(x) ++ "in"
  | Mm(x) => Js.Float.toString(x) ++ "mm"
  | Pc(x) => Js.Float.toString(x) ++ "pc"
  | Pt(x) => Js.Float.toString(x) ++ "pt"
  };

type color =
  | RGB(int, int, int)
  | RGBA(int, int, int, int)
  | Color(string);

let colorToString: option(color) => string = {
  let rgbColorToString = (r, g, b) =>
    "rgb("
    ++ Js.Int.toString(r)
    ++ ","
    ++ Js.Int.toString(g)
    ++ ","
    ++ Js.Int.toString(b)
    ++ ")";
  let rgbaColorToString = (r, g, b, a) =>
    "rgba("
    ++ Js.Int.toString(r)
    ++ ","
    ++ Js.Int.toString(g)
    ++ ","
    ++ Js.Int.toString(b)
    ++ ","
    ++ Js.Int.toString(a)
    ++ ")";
  value =>
    switch (value) {
    | None => commonAttr.none
    | Some(RGB(r, g, b)) => rgbColorToString(r, g, b)
    | Some(RGBA(r, g, b, a)) => rgbaColorToString(r, g, b, a)
    | Some(Color(value)) => value
    };
};

type scale =
  | Min
  | Mid
  | Max;

let scaleToString = scale =>
  switch (scale) {
  | Min => "Min"
  | Mid => "Mid"
  | Max => "Max"
  };

/**
 *  SVG Types
 * */
/* import Color exposing (Color) */
type accumulate =
  | Sum;

let accumulateToString = option =>
  switch (option) {
  | None => commonAttr.none
  | Some(Sum) => "sum"
  };

type additive =
  | Replace;

let additiveToString = option =>
  switch (option) {
  | None => commonAttr.none
  | Some(Replace) => "replace"
  };

type align =
  | Align(scale, scale);

let alignToString = option =>
  switch (option) {
  | None => commonAttr.none
  | Some(Align(x, y)) =>
    "X" ++ scaleToString(x) ++ "Y" ++ scaleToString(y)
  };

type alignmentBaseline =
  | Auto
  | Inherit
  | Baseline
  | BeforeEdge
  | TextBeforeEdge
  | Middle
  | Central
  | AfterEdge
  | TextAfterEdge
  | Ideographic
  | Alphabetic
  | Hanging
  | Mathematical;

let alignmentBaselineToString = value =>
  switch (value) {
  | Auto => commonAttr.auto
  | Inherit => commonAttr.inherit_
  | Baseline => "baseline"
  | BeforeEdge => "before-edge"
  | TextBeforeEdge => "text-before-edge"
  | Middle => "middle"
  | Central => "central"
  | AfterEdge => "after-edge"
  | TextAfterEdge => "text-after-edge"
  | Ideographic => "ideographic"
  | Alphabetic => "alphabetic"
  | Hanging => "hanging"
  | Mathematical => "mathematical"
  };

type anchorAlignment =
  | Inherit
  | Start
  | Middle
  | End;

let anchorAlignmentToString = value =>
  switch (value) {
  | Inherit => commonAttr.inherit_
  | Start => "start"
  | Middle => "middle"
  | End => "end"
  };

type animateTransformType =
  | Translate
  | Scale
  | Rotate
  | SkewX
  | SkewY;

let animateTransformTypeToString = value =>
  switch (value) {
  | Translate => "translate"
  | Scale => "scale"
  | Rotate => "rotate"
  | SkewX => "skewX"
  | SkewY => "skewY"
  };

type attributeType =
  | Auto
  | CSS
  | XML;

let attributeTypeToString = value =>
  switch (value) {
  | Auto => commonAttr.auto
  | CSS => "CSS"
  | XML => "XML"
  };

type baselineShift =
  | Auto
  | Inherit
  | Baseline
  | Super
  | Sub
  | Percentage(float)
  | Length(length);

let baselineShiftToString = value =>
  switch (value) {
  | Auto => commonAttr.auto
  | Inherit => commonAttr.inherit_
  | Baseline => "baseline"
  | Super => "super"
  | Sub => "sub"
  | Percentage(pct) => string_of_float(pct) ++ "%"
  | Length(length) => lengthToString(length)
  };

type bezierAnchorPoint = (float, float, float, float);

let bezierAnchorPointToString = ((x1, y1, x2, y2)) =>
  string_of_float(x1)
  ++ " "
  ++ string_of_float(y1)
  ++ " "
  ++ string_of_float(x2)
  ++ " "
  ++ string_of_float(y2);

type calcMode =
  | Discrete
  | Linear
  | Paced
  | Spline;

let calcModeToString = value =>
  switch (value) {
  | Discrete => "discrete"
  | Linear => "linear"
  | Paced => "paced"
  | Spline => "spline"
  };

type clip =
  | Auto
  | Inherit
  | Shape(length, length, length, length);

let clipToString = value =>
  switch (value) {
  | Auto => commonAttr.auto
  | Inherit => commonAttr.inherit_
  | Shape(top, right, bottom, left) =>
    "rect("
    ++ lengthToString(top)
    ++ " "
    ++ lengthToString(right)
    ++ " "
    ++ lengthToString(bottom)
    ++ " "
    ++ lengthToString(left)
    ++ ")"
  };

type clipPath =
  | Inherit
  | Func(string);

let clipPathToString = option =>
  switch (option) {
  | None => commonAttr.none
  | Some(Inherit) => commonAttr.inherit_
  | Some(Func(str)) => str
  };

type clipRule =
  | NonZero
  | EvenOdd
  | Inherit;

let clipRuleToString = value =>
  switch (value) {
  | NonZero => "nonzero"
  | EvenOdd => "evenodd"
  | Inherit => commonAttr.inherit_
  };

type colorInterpolation =
  | Auto
  | SRGB
  | LinearRGB
  | Inherit;

let colorInterpolationToString = value =>
  switch (value) {
  | Auto => commonAttr.auto
  | Inherit => commonAttr.inherit_
  | SRGB => "sRGB"
  | LinearRGB => "linearRGB"
  };

type colorMatrixType =
  | Matrix
  | Saturate
  | HueRotate
  | LuminanceToAlpha;

let colorMatrixTypeToString = value =>
  switch (value) {
  | Matrix => "matrix"
  | Saturate => "saturate"
  | HueRotate => "hueRotate"
  | LuminanceToAlpha => "luminanceToAlpha"
  };

type colorProfile =
  | Auto
  | SRGB
  | Named(string)
  | Inherit;

let colorProfileToString = value =>
  switch (value) {
  | Auto => commonAttr.auto
  | Inherit => commonAttr.inherit_
  | SRGB => "sRGB"
  | Named(name) => name
  };

type compositeOperator =
  | Over
  | In
  | Out
  | Atop
  | Xor
  | Arithmetic;

let compositeOperatorToString = value =>
  switch (value) {
  | Over => "over"
  | In => "in"
  | Out => "out"
  | Atop => "atop"
  | Xor => "xor"
  | Arithmetic => "arithmetic"
  };

type coordinateSystem =
  | UserSpaceOnUse
  | ObjectBoundingBox;

let coordinateSystemToString = value =>
  switch (value) {
  | UserSpaceOnUse => "userSpaceOnUse"
  | ObjectBoundingBox => "objectBoundingBox"
  };

type cursor =
  | Auto
  | Inherit
  | Default
  | Crosshair
  | Pointer
  | Move
  | EResize
  | NEResize
  | NWResize
  | NResize
  | SEResize
  | SWResize
  | WResize
  | Text
  | Wait
  | Help
  | FuncIRI(string);

let cursorToString = value =>
  switch (value) {
  | Auto => commonAttr.auto
  | Inherit => commonAttr.inherit_
  | Default => "default"
  | Crosshair => "crosshair"
  | Pointer => "pointer"
  | Move => "move"
  | EResize => "e-resize"
  | NEResize => "ne-resize"
  | NWResize => "nw-resize"
  | NResize => "n-resize"
  | SEResize => "se-resize"
  | SWResize => "sw-resize"
  | WResize => "w-resize"
  | Text => "text"
  | Wait => "wait"
  | Help => "help"
  | FuncIRI(str) => str
  };

type direction =
  | Inherit
  | LeftToRight
  | RightToLeft;

let directionToString = value =>
  switch (value) {
  | Inherit => commonAttr.inherit_
  | LeftToRight => "ltr"
  | RightToLeft => "rtl"
  };

type display =
  | None
  | Inline
  | Block
  | ListItem
  | RunIn
  | Compact
  | Marker
  | Table
  | InlineTable
  | TableRowGroup
  | TableHeaderGroup
  | TableFooterGroup
  | TableRow
  | TableColumnGroup
  | TableColumn
  | TableCell
  | TableCaption
  | Inherit;

let displayToString = value =>
  switch (value) {
  | None => commonAttr.none
  | Inherit => commonAttr.inherit_
  | Inline => "inline"
  | Block => "block"
  | ListItem => "list-item"
  | RunIn => "run-in"
  | Compact => "compact"
  | Marker => "marker"
  | Table => "table"
  | InlineTable => "inline-table"
  | TableRowGroup => "table-row-group"
  | TableHeaderGroup => "table-header-group"
  | TableFooterGroup => "table-footer-group"
  | TableRow => "table-row"
  | TableColumnGroup => "table-column-group"
  | TableColumn => "table-column"
  | TableCell => "table-cell"
  | TableCaption => "table-caption"
  };

type dominantBaseline =
  | Auto
  | Inherit
  | UseScript
  | NoChange
  | ResetSize
  | Ideographic
  | Alphabetic
  | Hanging
  | Mathematical
  | Central
  | Middle
  | TextAfterEdge
  | TextBeforeEdge;

let dominantBaselineToString = value =>
  switch (value) {
  | Auto => commonAttr.auto
  | Inherit => commonAttr.inherit_
  | UseScript => "use-script"
  | NoChange => "no-change"
  | ResetSize => "reset-size"
  | Ideographic => "ideographic"
  | Alphabetic => "alphabetic"
  | Hanging => "hanging"
  | Mathematical => "mathematical"
  | Central => "central"
  | Middle => "middle"
  | TextAfterEdge => "text-after-edge"
  | TextBeforeEdge => "text-before-edge"
  };

type duration =
  | Duration(clockValue)
  | Indefinite;

let durationToString = value =>
  switch (value) {
  | Duration(clockValue) => clockValue
  | Indefinite => "indefinite"
  };

type edgeMode =
  | None
  | Duplicate
  | Wrap;

let edgeModeToString = value =>
  switch (value) {
  | None => commonAttr.none
  | Duplicate => "duplicate"
  | Wrap => "wrap"
  };

type fillRule =
  | NonZero
  | EvenOdd;

let fillRuleToString = value =>
  switch (value) {
  | NonZero => "nonzero"
  | EvenOdd => "evenodd"
  };

type filter =
  | None
  | Inherit
  | Filter(string);

let filterToString = value =>
  switch (value) {
  | None => commonAttr.none
  | Inherit => commonAttr.inherit_
  | Filter(str) => str
  };

type floodColor =
  | Inherit
  | CurrentColor
  | ICC(string)
  | Flood(color);

let floodColorToString = value =>
  switch (value) {
  | Inherit => commonAttr.inherit_
  | CurrentColor => "currentcolor"
  | ICC(str) => str
  | Flood(color) => colorToString(Some(color))
  };

type fontFamily =
  | Inherit
  | Initial
  | Unset
  | Serif
  | SansSerif
  | Monospace
  | Cursive
  | Fantasy
  | SystemUI
  | FontName(string);

let fontFamilyToString = value =>
  switch (value) {
  | Inherit => commonAttr.inherit_
  | Initial => "initial"
  | Unset => "unset"
  | Serif => "serif"
  | SansSerif => "sans-serif"
  | Monospace => "monospace"
  | Cursive => "cursive"
  | Fantasy => "fantasy"
  | SystemUI => "system-ui"
  | FontName(name) => name
  };

type fontSizeAdjust =
  | None
  | Inherit
  | Adjust(float);

let fontSizeAdjustToString = value =>
  switch (value) {
  | None => commonAttr.none
  | Inherit => commonAttr.inherit_
  | Adjust(aspect) => string_of_float(aspect)
  };

type fontStretch =
  | Inherit
  | Normal
  | Wider
  | Narrower
  | UltraCondensed
  | ExtraCondensed
  | Condensed
  | SemiCondensed
  | SemiExpanded
  | Expanded
  | ExtraExpanded
  | UltraExpanded;

let fontStretchToString = value =>
  switch (value) {
  | Inherit => commonAttr.inherit_
  | Normal => "normal"
  | Wider => "winder"
  | Narrower => "narrower"
  | UltraCondensed => "ultra-condensed"
  | ExtraCondensed => "extra-condensed"
  | Condensed => "condensed"
  | SemiCondensed => "semi-condensed"
  | SemiExpanded => "semi-expanded"
  | Expanded => "expanded"
  | ExtraExpanded => "extra-expanded"
  | UltraExpanded => "ultra-expanded"
  };

type fontStyle =
  | Inherit
  | Normal
  | Italic
  | Oblique;

let fontStyleToString = value =>
  switch (value) {
  | Inherit => "inherit"
  | Normal => "normal"
  | Italic => "italic"
  | Oblique => "oblique"
  };

type fontVariant =
  | Inherit
  | Normal
  | SmallCaps;

let fontVariantToString = value =>
  switch (value) {
  | Inherit => commonAttr.inherit_
  | Normal => "normal"
  | SmallCaps => "small-caps"
  };

type fontWeight =
  | Inherit
  | Normal
  | Bold
  | Bolder
  | Lighter
  | FontWeight(int);

let fontWeightToString = value =>
  switch (value) {
  | Inherit => commonAttr.inherit_
  | Normal => "normal"
  | Bold => "bold"
  | Bolder => "bolder"
  | Lighter => "lighter"
  | FontWeight(weight) => string_of_int(weight)
  };

type funcType =
  | Identity
  | Table
  | Discrete
  | Linear
  | Gamma;

let funcTypeToString = value =>
  switch (value) {
  | Identity => "identity"
  | Table => "table"
  | Discrete => "discrete"
  | Linear => "linear"
  | Gamma => "gamma"
  };

type inValue =
  | SourceGraphic
  | SourceAlpha
  | BackgroundAlpha
  | FillPaint
  | StrokePaint
  | Reference(string);

let inValueToString = value =>
  switch (value) {
  | SourceGraphic => "sourceGraphic"
  | SourceAlpha => "sourceAlpha"
  | BackgroundAlpha => "backgroundAlpha"
  | FillPaint => "fillPaint"
  | StrokePaint => "strokePaint"
  | Reference(ref) => ref
  };

type kerning =
  | Auto
  | Inherit
  | Kerning(length);

let kerningToString = value =>
  switch (value) {
  | Auto => commonAttr.auto
  | Inherit => commonAttr.inherit_
  | Kerning(len) => lengthToString(len)
  };

type lengthAdjust =
  | Spacing
  | SpacingAndGlyphs;

let lengthAdjust = value =>
  switch (value) {
  | Spacing => "spacing"
  | SpacingAndGlyphs => "spacingAndGlyphs"
  };

type markerCoordinateSystem =
  | UserSpaceOnUse
  | StrokeWidth;

let markerCoordinateSystemToString = value =>
  switch (value) {
  | UserSpaceOnUse => "userSpaceOnUse"
  | StrokeWidth => "strokeWidth"
  };

type meetOrSlice =
  | Meet
  | Slice;

let meetOrSliceToString = value =>
  switch (value) {
  | Meet => "meet"
  | Slice => "slice"
  };

type mode =
  | Normal
  | Multiply
  | Screen
  | Darken
  | Lighten;

let modeToString = value =>
  switch (value) {
  | Normal => "normal"
  | Multiply => "multiply"
  | Screen => "screen"
  | Darken => "darken"
  | Lighten => "lighten"
  };

type morphologyOperator =
  | Erode
  | Dilate;

let morphologyOperatorToString = value =>
  switch (value) {
  | Erode => "erode"
  | Dilate => "dilate"
  };

type opacity =
  | Inherit
  | Opacity(float);

let opacityToString = value =>
  switch (value) {
  | Inherit => commonAttr.inherit_
  | Opacity(opacity) => string_of_float(opacity)
  };

type rendering =
  | Inherit
  | Auto
  | OptimizeSpeed
  | OptimizeQuality;

let renderingToString = value =>
  switch (value) {
  | Inherit => commonAttr.inherit_
  | Auto => commonAttr.auto
  | OptimizeSpeed => "optimizeSpeed"
  | OptimizeQuality => "optimizeQuality"
  };

type repeatCount =
  | Repeat(int)
  | Indefinite;

let repeatCountToString = value =>
  switch (value) {
  | Indefinite => "indefinite"
  | Repeat(count) => string_of_int(count)
  };

type restart =
  | Always
  | Never
  | WhenNotActive;

let restartToString = value =>
  switch (value) {
  | Always => "always"
  | Never => "never"
  | WhenNotActive => "whenNotActive"
  };

type shapeRendering =
  | Auto
  | Inherit
  | OptimizeSpeed
  | CrispEdges
  | GeometricPrecision;

let shapeRendering = value =>
  switch (value) {
  | Auto => commonAttr.auto
  | Inherit => commonAttr.inherit_
  | OptimizeSpeed => "optimizeSpeed"
  | CrispEdges => "crispEdges"
  | GeometricPrecision => "geometricPrecision"
  };

/* The stroke-linecap attribute specifies the shape to be used at the end of open subpaths when they are stroked. */
type strokeLineCap =
  | Inherit
  | Butt
  | Round
  | Square;

let strokeLineCap = value =>
  switch (value) {
  | Inherit => commonAttr.inherit_
  | Butt => "butt"
  | Round => "round"
  | Square => "square"
  };

/*
 The stroke-linejoin attribute specifies the shape to be used at the corners of paths or basic shapes when they are stroked.

 As a presentation attribute, it also can be used as a property directly inside a CSS stylesheet.

 Note: the final appearence of the miter option is also influenced by the stroke-miterlimit attribute.
 */
type strokeLineJoin =
  | Inherit
  | Miter
  | Round
  | Bevel;

let strokeLineJoin = value =>
  switch (value) {
  | Inherit => commonAttr.inherit_
  | Miter => "miter"
  | Round => "round"
  | Bevel => "bevel"
  };

/*
 The creator of SVG content might want to provide a hint about what tradeoffs to make as the browser renders text. The text-rendering attribute provides these hints.

 As a presentation attribute, it also can be used as a property directly inside a CSS stylesheet, see css text-rendering for further information.
 */
type textRendering =
  | Inherit
  | Auto
  | OptimizeSpeed
  | OptimizeLegibility
  | GeometricPrecision;

let textRenderingToString = value =>
  switch (value) {
  | Inherit => commonAttr.inherit_
  | Auto => commonAttr.auto
  | OptimizeSpeed => "optimizeSpeed"
  | OptimizeLegibility => "optimizeLegibility"
  | GeometricPrecision => "geometricPrecision"
  };

/* The Transform type is used by `transform` and `gradientTransform`. */
type transform =
  | Matrix(float, float, float, float, float, float)
  | Rotate(float)
  | RotateXY(float, float, float)
  | Scale(float)
  | ScaleXY(float, float)
  | SkewX(float)
  | SkewY(float)
  | Translate(float, float);

let transformToString = value => {
  let parens = (name, args) =>
    name ++ "(" ++ " " ++ Utils.joinFloats(args, " ") ++ ")";
  switch (value) {
  | Matrix(a, b, c, d, e, f) => parens("matrix", [a, b, c, d, e, f])
  | Rotate(a) => parens("rotate", [a])
  | RotateXY(a, x, y) => parens("rotate", [a, x, y])
  | Scale(xy) => parens("scale", [xy])
  | ScaleXY(x, y) => parens("scale", [x, y])
  | SkewX(x) => parens("skewX", [x])
  | SkewY(y) => parens("skewY", [y])
  | Translate(x, y) => parens("translate", [x, y])
  };
};

/* Used by `begin` and `end` in constraining animation times */
type timingValue =
  | OffsetValue(clockValue)
  | SyncBaseValue(string)
  | EventValue(string)
  | RepeatValue(string)
  | AccessKeyValue(string)
  | WallclockSyncValue(string)
  | Indefinite;

let timingValueToString = value =>
  switch (value) {
  | OffsetValue(clock) => clock
  | SyncBaseValue(str) => str
  | EventValue(str) => str
  | RepeatValue(str) => str
  | AccessKeyValue(str) => str
  | WallclockSyncValue(str) => str
  | Indefinite => "indefinite"
  };

type turbulenceType =
  | FractalNoise
  | Turbulence;

let turbulenceTypeToString = value =>
  switch (value) {
  | FractalNoise => "fractalNoise"
  | Turbulence => "turbulence"
  };

/* Used by allowReorder */
type yesNo =
  | Yes
  | No;

let yesNoToString = value =>
  switch (value) {
  | Yes => "yes"
  | No => "no"
  };