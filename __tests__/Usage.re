open Jest;

open ExpectJs;

/* open TypedSvg; */
let svg = (~key="", ~unique="", ~length=TypedSvg_Types.px, props, nodes) =>
  Vdom.fullnode(Tea.Svg.svgNamespace, "svg", key, unique, props, nodes);

let () =
  describe("Usage", () => {
    test("should be 1", () =>
      expect(1) |> toEqual(1)
    );
    test("svg", ()
      /* svg(~length=px, []) */
      =>
        expect(1) |> toEqual(2)
      );
  });