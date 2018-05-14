open Vdom;

open TypedSvg_Types;

let cx: length => Vdom.property('a) =
  length => attribute("", "cx", lengthToString(length));

let cy: length => Vdom.property('a) =
  length => attribute("", "cy", lengthToString(length));

let dx: length => Vdom.property('a) =
  length => attribute("", "dx", lengthToString(length));

let dy: length => Vdom.property('a) =
  length => attribute("", "dy", lengthToString(length));

let fontSize: length => Vdom.property('a) =
  length => attribute("", "fontSize", lengthToString(length));

let fx: length => Vdom.property('a) =
  length => attribute("", "fx", lengthToString(length));

let fy: length => Vdom.property('a) =
  length => attribute("", "fy", lengthToString(length));

let height: length => Vdom.property('a) =
  length => attribute("", "height", lengthToString(length));

let width: length => Vdom.property('a) =
  length => attribute("", "width", lengthToString(length));

let markerHeight: length => Vdom.property('a) =
  length => attribute("", "markerHeight", lengthToString(length));

let markerWidth: length => Vdom.property('a) =
  length => attribute("", "markerWidth", lengthToString(length));

let r: length => Vdom.property('a) =
  length => attribute("", "r", lengthToString(length));

let rx: length => Vdom.property('a) =
  length => attribute("", "rx", lengthToString(length));

let ry: length => Vdom.property('a) =
  length => attribute("", "ry", lengthToString(length));

let textLength: length => Vdom.property('a) =
  length => attribute("", "textLength", lengthToString(length));

let strokeWidth: length => Vdom.property('a) =
  length => attribute("", "strokeWidth", lengthToString(length));

let x: length => Vdom.property('a) =
  length => attribute("", "x", lengthToString(length));

let y: length => Vdom.property('a) =
  length => attribute("", "y", lengthToString(length));

let x1: length => Vdom.property('a) =
  length => attribute("", "x1", lengthToString(length));

let y1: length => Vdom.property('a) =
  length => attribute("", "y1", lengthToString(length));

let x2: length => Vdom.property('a) =
  length => attribute("", "x2", lengthToString(length));

let y2: length => Vdom.property('a) =
  length => attribute("", "y2", lengthToString(length));