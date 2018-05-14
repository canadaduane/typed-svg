open Vdom;

open TypedSvg_Types;

module type LengthUnit = {type t; let toLength: t => length;};

module NumUnits = {
  type t = float;
  let toLength = (value: t) => num(value);
};

module PercentUnits = {
  type t = float;
  let toLength = (value: t) => percent(value);
};

module PxUnits = {
  type t = float;
  let toLength = (value: t) => px(value);
};

module CmUnits = {
  type t = float;
  let toLength = (value: t) => cm(value);
};

module EmUnits = {
  type t = float;
  let toLength = (value: t) => em(value);
};

module ExUnits = {
  type t = float;
  let toLength = (value: t) => ex(value);
};

module InchUnits = {
  type t = float;
  let toLength = (value: t) => inch(value);
};

module MmUnits = {
  type t = float;
  let toLength = (value: t) => mm(value);
};

module PcUnits = {
  type t = float;
  let toLength = (value: t) => pc(value);
};

module PtUnits = {
  type t = float;
  let toLength = (value: t) => pt(value);
};

module Default = (Measurement: LengthUnit) => {
  let attr = (a, l) =>
    attribute("", a, lengthToString(Measurement.toLength(l)));
  let cx: Measurement.t => Vdom.property('a) = l => attr("cx", l);
  let cy: Measurement.t => Vdom.property('a) = l => attr("cy", l);
  let dx: Measurement.t => Vdom.property('a) = l => attr("dx", l);
  let dy: Measurement.t => Vdom.property('a) = l => attr("dy", l);
  let fontSize: Measurement.t => Vdom.property('a) =
    l => attr("fontSize", l);
  let fx: Measurement.t => Vdom.property('a) = l => attr("fx", l);
  let fy: Measurement.t => Vdom.property('a) = l => attr("fy", l);
  let height: Measurement.t => Vdom.property('a) = l => attr("height", l);
  let width: Measurement.t => Vdom.property('a) = l => attr("width", l);
  let markerHeight: Measurement.t => Vdom.property('a) =
    l => attr("markerHeight", l);
  let markerWidth: Measurement.t => Vdom.property('a) =
    l => attr("markerWidth", l);
  let r: Measurement.t => Vdom.property('a) = l => attr("r", l);
  let rx: Measurement.t => Vdom.property('a) = l => attr("rx", l);
  let ry: Measurement.t => Vdom.property('a) = l => attr("ry", l);
  let textLength: Measurement.t => Vdom.property('a) =
    l => attr("textLength", l);
  let strokeWidth: Measurement.t => Vdom.property('a) =
    l => attr("strokeWidth", l);
  let x: Measurement.t => Vdom.property('a) = l => attr("x", l);
  let y: Measurement.t => Vdom.property('a) = l => attr("y", l);
  let x1: Measurement.t => Vdom.property('a) = l => attr("x1", l);
  let y1: Measurement.t => Vdom.property('a) = l => attr("y1", l);
  let x2: Measurement.t => Vdom.property('a) = l => attr("x2", l);
  let y2: Measurement.t => Vdom.property('a) = l => attr("y2", l);
};

let attr = (a, l) => attribute("", a, lengthToString(l));

/* Generic length properties, useful when a length is needed outside of the 'default' units */
let cx: length => Vdom.property('a) = l => attr("cx", l);

let cy: length => Vdom.property('a) = l => attr("cy", l);

let dx: length => Vdom.property('a) = l => attr("dx", l);

let dy: length => Vdom.property('a) = l => attr("dy", l);

let fontSize: length => Vdom.property('a) = l => attr("fontSize", l);

let fx: length => Vdom.property('a) = l => attr("fx", l);

let fy: length => Vdom.property('a) = l => attr("fy", l);

let height: length => Vdom.property('a) = l => attr("height", l);

let width: length => Vdom.property('a) = l => attr("width", l);

let markerHeight: length => Vdom.property('a) = l => attr("markerHeight", l);

let markerWidth: length => Vdom.property('a) = l => attr("markerWidth", l);

let r: length => Vdom.property('a) = l => attr("r", l);

let rx: length => Vdom.property('a) = l => attr("rx", l);

let ry: length => Vdom.property('a) = l => attr("ry", l);

let textLength: length => Vdom.property('a) = l => attr("textLength", l);

let strokeWidth: length => Vdom.property('a) = l => attr("strokeWidth", l);

let x: length => Vdom.property('a) = l => attr("x", l);

let y: length => Vdom.property('a) = l => attr("y", l);

let x1: length => Vdom.property('a) = l => attr("x1", l);

let y1: length => Vdom.property('a) = l => attr("y1", l);

let x2: length => Vdom.property('a) = l => attr("x2", l);

let y2: length => Vdom.property('a) = l => attr("y2", l);