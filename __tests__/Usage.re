open Jest;

open ExpectJs;

open TypedSvg.Types;

/* open TypedSvg; */
/* let svg = (~key="", ~unique="", ~options=defaultSvgOptions, props, nodes) =>
   Vdom.fullnode(Tea.Svg.svgNamespace, "svg", key, unique, props, mergeOptions(options, nodes));

   let svg = (w:Measurement.t, h:Measurement.t, ~maxX=100., ~maxY=100., children) =>
   Tea.Svg.svg(
     [
       width(w),
       height(h),
       viewBox(0., 0., maxX, maxY)
     ],
     children
   ); */
let () =
  describe("Units", () => {
    /* Explicit Units */
    test("length props can use explicit num (bare) units", () =>
      TypedSvg.Units.(
        expect(x1(num(1.))) |> toEqual(Vdom.attribute("", "x1", "1"))
      )
    );
    test("length props can use explicit percent units", () =>
      TypedSvg.Units.(
        expect(x1(percent(10.)))
        |> toEqual(Vdom.attribute("", "x1", "10%"))
      )
    );
    test("length props can use explicit px units", () =>
      TypedSvg.Units.(
        expect(x1(px(1.))) |> toEqual(Vdom.attribute("", "x1", "1px"))
      )
    );
    test("length props can use explicit cm units", () =>
      TypedSvg.Units.(
        expect(x1(cm(1.))) |> toEqual(Vdom.attribute("", "x1", "1cm"))
      )
    );
    test("length props can use explicit em units", () =>
      TypedSvg.Units.(
        expect(x1(em(1.))) |> toEqual(Vdom.attribute("", "x1", "1em"))
      )
    );
    test("length props can use explicit ex units", () =>
      TypedSvg.Units.(
        expect(x1(ex(1.))) |> toEqual(Vdom.attribute("", "x1", "1ex"))
      )
    );
    test("length props can use explicit inch units", () =>
      TypedSvg.Units.(
        expect(x1(inch(1.))) |> toEqual(Vdom.attribute("", "x1", "1in"))
      )
    );
    test("length props can use explicit mm units", () =>
      TypedSvg.Units.(
        expect(x1(mm(1.))) |> toEqual(Vdom.attribute("", "x1", "1mm"))
      )
    );
    test("length props can use explicit pc units", () =>
      TypedSvg.Units.(
        expect(x1(pc(1.))) |> toEqual(Vdom.attribute("", "x1", "1pc"))
      )
    );
    test("length props can use explicit pt units", () =>
      TypedSvg.Units.(
        expect(x1(pt(1.))) |> toEqual(Vdom.attribute("", "x1", "1pt"))
      )
    );
    /* Default Units */
    test("length props can have default num (bare) units", () =>
      TypedSvg.NumUnits.(
        expect(x1(1.)) |> toEqual(Vdom.attribute("", "x1", "1"))
      )
    );
    test("length props can have default percent units", () =>
      TypedSvg.PercentUnits.(
        expect(x1(100.)) |> toEqual(Vdom.attribute("", "x1", "100%"))
      )
    );
    test("length props can have default px units", () =>
      TypedSvg.PxUnits.(
        expect(x1(1.)) |> toEqual(Vdom.attribute("", "x1", "1px"))
      )
    );
    test("length props can have default cm units", () =>
      TypedSvg.CmUnits.(
        expect(x1(1.)) |> toEqual(Vdom.attribute("", "x1", "1cm"))
      )
    );
    test("length props can have default em units", () =>
      TypedSvg.EmUnits.(
        expect(x1(1.)) |> toEqual(Vdom.attribute("", "x1", "1em"))
      )
    );
    test("length props can have default ex units", () =>
      TypedSvg.ExUnits.(
        expect(x1(1.)) |> toEqual(Vdom.attribute("", "x1", "1ex"))
      )
    );
    test("length props can have default inch units", () =>
      TypedSvg.InchUnits.(
        expect(x1(1.)) |> toEqual(Vdom.attribute("", "x1", "1in"))
      )
    );
    test("length props can have default mm units", () =>
      TypedSvg.MmUnits.(
        expect(x1(1.)) |> toEqual(Vdom.attribute("", "x1", "1mm"))
      )
    );
    test("length props can have default pc units", () =>
      TypedSvg.PcUnits.(
        expect(x1(1.)) |> toEqual(Vdom.attribute("", "x1", "1pc"))
      )
    );
    test("length props can have default pt units", () =>
      TypedSvg.PtUnits.(
        expect(x1(1.)) |> toEqual(Vdom.attribute("", "x1", "1pt"))
      )
    );
  });