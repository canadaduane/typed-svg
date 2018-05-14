open Vdom;

let cx: float => Vdom.property('a) =
  value => attribute("", "cx", Js.Float.toString(value) ++ "px");

let cy: float => Vdom.property('a) =
  value => attribute("", "cy", Js.Float.toString(value) ++ "px");

let dx: float => Vdom.property('a) =
  value => attribute("", "dx", Js.Float.toString(value) ++ "px");

let dy: float => Vdom.property('a) =
  value => attribute("", "dy", Js.Float.toString(value) ++ "px");

let fontSize: float => Vdom.property('a) =
  value => attribute("", "font-size", Js.Float.toString(value) ++ "px");

let fx: float => Vdom.property('a) =
  value => attribute("", "fx", Js.Float.toString(value) ++ "px");

let fy: float => Vdom.property('a) =
  value => attribute("", "fy", Js.Float.toString(value) ++ "px");

let height: float => Vdom.property('a) =
  value => attribute("", "height", Js.Float.toString(value) ++ "px");

let width: float => Vdom.property('a) =
  value => attribute("", "width", Js.Float.toString(value) ++ "px");

let markerHeight: float => Vdom.property('a) =
  value => attribute("", "markerHeight", Js.Float.toString(value) ++ "px");

let markerWidth: float => Vdom.property('a) =
  value => attribute("", "markerWidth", Js.Float.toString(value) ++ "px");

let r: float => Vdom.property('a) =
  value => attribute("", "r", Js.Float.toString(value) ++ "px");

let rx: float => Vdom.property('a) =
  value => attribute("", "rx", Js.Float.toString(value) ++ "px");

let ry: float => Vdom.property('a) =
  value => attribute("", "ry", Js.Float.toString(value) ++ "px");

let textLength: float => Vdom.property('a) =
  value => attribute("", "textLength", Js.Float.toString(value) ++ "px");

let strokeWidth: float => Vdom.property('a) =
  value => attribute("", "strokeWidth", Js.Float.toString(value) ++ "px");

let x: float => Vdom.property('a) =
  value => attribute("", "x", Js.Float.toString(value) ++ "px");

let y: float => Vdom.property('a) =
  value => attribute("", "y", Js.Float.toString(value) ++ "px");

let x1: float => Vdom.property('a) =
  value => attribute("", "x1", Js.Float.toString(value) ++ "px");

let y1: float => Vdom.property('a) =
  value => attribute("", "y1", Js.Float.toString(value) ++ "px");

let x2: float => Vdom.property('a) =
  value => attribute("", "x2", Js.Float.toString(value) ++ "px");

let y2: float => Vdom.property('a) =
  value => attribute("", "y2", Js.Float.toString(value) ++ "px");