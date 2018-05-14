module Utils = TypedSvg_Utils;

module Attributes = TypedSvg_Attributes;

module Types = TypedSvg_Types;

module Units = TypedSvg_Units;

module NumUnits = TypedSvg_Units.Default(TypedSvg_Units.NumUnits);

module PercentUnits = TypedSvg_Units.Default(TypedSvg_Units.PercentUnits);

module PxUnits = TypedSvg_Units.Default(TypedSvg_Units.PxUnits);

module CmUnits = TypedSvg_Units.Default(TypedSvg_Units.CmUnits);

module EmUnits = TypedSvg_Units.Default(TypedSvg_Units.EmUnits);

module ExUnits = TypedSvg_Units.Default(TypedSvg_Units.ExUnits);

module InchUnits = TypedSvg_Units.Default(TypedSvg_Units.InchUnits);

module MmUnits = TypedSvg_Units.Default(TypedSvg_Units.MmUnits);

module PcUnits = TypedSvg_Units.Default(TypedSvg_Units.PcUnits);

module PtUnits = TypedSvg_Units.Default(TypedSvg_Units.PtUnits);

let svgNamespace = Tea.Svg.svgNamespace;

let circle = (~key="", ~unique="", props) =>
  Vdom.fullnode(svgNamespace, "circle", key, unique, props, []);

let ellipse = (~key="", ~unique="", props) =>
  Vdom.fullnode(svgNamespace, "ellipse", key, unique, props, []);

let line = (~key="", ~unique="", props) =>
  Vdom.fullnode(svgNamespace, "line", key, unique, props, []);

let polygon = (~key="", ~unique="", props) =>
  Vdom.fullnode(svgNamespace, "polygon", key, unique, props, []);

let polyline = (~key="", ~unique="", props) =>
  Vdom.fullnode(svgNamespace, "polyline", key, unique, props, []);

let rect = (~key="", ~unique="", props) =>
  Vdom.fullnode(svgNamespace, "rect", key, unique, props, []);

let g = Tea.Svg.g;