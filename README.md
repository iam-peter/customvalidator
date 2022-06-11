# Custom QValidator

This is an example of a custom QValidator written as an answer on this stackoverflow [question](https://stackoverflow.com/questions/72572951/qml-textinput-inputmask-with-multiple-mask-guards).

The validator excepts the following inputs:

1. dddd
2. dddd-dddd

where in the second case the right hand side (rhs) must be bigger than the left hand side (lhs).

Acceptable inputs:
- 1234
- 1234-5678
- 9998-9999

Invalid inputs:
- 123
- 1234-23
- 1234-1234
