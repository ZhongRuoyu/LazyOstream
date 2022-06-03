# LazyOstream

This is a simple library that wraps C++'s `std::basic_ostream` for lazy
evaluation. Streams can be disabled, and when they are, output is not
evaluated. This can be achieved without having to rebuild the binary or define
any additional debugging flags, making it very suitable for logging and
debugging purposes.

## Interfaces

It provides a general interface, `LAZY_OSTREAM(ostream, enabled)`. When
`enabled` is set to `true`, it behaves normally like the `ostream` itself;
when `enabled` is set to `false`, however, anything passed to it is not
evaluated. In addition, similar to `iostream`, it also defines the following
three shortcuts for the standard output streams: `LAZY_COUT(enabled)`,
`LAZY_CERR(enabled)`, `LAZY_CLOG(enabled)`.

## Examples

See [here](examples) for a set of examples.

## License

Copyright (c) 2022 Zhong Ruoyu. Licensed under [the MIT License](LICENSE).
