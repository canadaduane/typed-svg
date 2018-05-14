let joinStrings = (strings, sep) =>
  switch (List.length(strings)) {
  | 0 => ""
  | 1 => List.hd(strings)
  | _ =>
    List.fold_left(
      (w1, w2) => w1 ++ sep ++ w2,
      List.hd(strings),
      List.tl(strings),
    )
  };

let joinFloats = (vals, sep) =>
  joinStrings(List.map(Js.Float.toString, vals), sep);