# code-digger

Code has a hidden universe, and you have to dig it to crack it open. Usually the compiler, the debugger, the OS are kind of black boxes, right?

## write a debugger to understand how debugger works

Tim is writing a debugger in Rust, and he uses [rust-sitter](https://github.com/hydro-project/rust-sitter) as a parser. This rust-sitter is based on another project, [tree-sitter](https://tree-sitter.github.io/tree-sitter/). This tree-sitter is a tool for generating fast, incremental parsers.

* [how debugger works](https://www.debuggingbook.org/html/Debugger.html)

* [write a debugger from scratch](https://www.timdbg.com/posts/writing-a-debugger-from-scratch-part-1/)

* [learn rust](https://www.rust-lang.org/learn)

* [python debugger from scratch in python](https://github.com/parttimenerd/python-dbg/), [blog post](https://mostlynerdless.de/blog/2023/09/20/lets-create-a-python-debugger-together-part-1/)

* [debugger for windows in C](https://ja.nsommer.dk/articles/x86-debugger-for-windows-and-wine.html)

* [c++ linux debugger setup](https://blog.tartanllama.xyz/writing-a-linux-debugger-setup/)

* [debugger](https://github.com/munificent/craftinginterpreters/issues/922)

* https://justine.lol/blinkenlights/

* https://eli.thegreenplace.net/tag/debuggers

* [LLDB Mac quick start](https://developer.apple.com/library/archive/documentation/IDEs/Conceptual/gdb_to_lldb_transition_guide/document/lldb-terminal-workflow-tutorial.html)

* [ptrace macos](https://www.spaceflint.com/?p=150)

* [ARM debugger](https://developer.arm.com/documentation/101469/2023-0/Introduction-to-Arm-Debugger)

* JS react debugger

* [blink emulator](https://github.com/jart/blink)

## assembly languages and other programming languages

Understanding asssembly language is essential to understanding how things really work. Complex or unfamiliar language features, undefined behavior, or simply poorly written code can be difficult to understand to see what's really going on. But the assembly code will always tell you the truth.

### x86 assembly: Intel vs. AT&T syntax flavors

```assembly
# intel syntax
add eax, 4

# AT&T syntax
addl $4, %eax

# -M intel for Intel syntax
objdump -d -M intel ./a.out
```

Besides the order being swapped, constants also get prefixed with ```$```, and registers are prefixed with ```%```. Some mnemonics also have a letter appended to indicate the size of the operands, such as ```l``` for 32-bit operands.

### ARM assembly

### RISC-V assembly

* [Godbolt compiler explorer](https://godbolt.org/)

* [Intel software developer manuals: SDM](https://www.intel.com/content/www/us/en/developer/articles/technical/intel-sdm.html)

