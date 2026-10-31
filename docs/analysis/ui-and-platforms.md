# Analysis: more UIs and platforms

Notes for later, not decisions: nothing here is scheduled. When a topic is decided, record the
decision in `docs/adr/`, and add its milestone and issues.

Data read from each project's pages on 2026-10-31, except where noted. Check licenses, prices and
activity again before deciding. The GitHub pages didn't show dates, so how active each project is
remains to be checked.

| Topic | First impression | Main open question |
|---|---|---|
| Text-based UI | FTXUI, as a new app next to the console menu | Is it worth adding a third frontend? |
| IoT and low-power devices | LVGL on a PC simulator | Do the inner layers fit the target device? |
| macOS | Tests in the CI, run by hand | Does the project build with Apple Clang? |
| Android | Qt on a real phone, after the Qt frontend | Where are the orders stored? |

## Text-based UI

Replace the console menu, or add to it, with a library for text-based interfaces.

| | [FTXUI](https://github.com/ArthurSonzogni/FTXUI) | [TUIKit](https://github.com/skhelladi/TUIKit) | [ImTui](https://github.com/ggerganov/imtui) |
|---|---|---|---|
| License | MIT | MIT | MIT |
| Dependencies | None | FTXUI, nlohmann/json, and `xxd` for embedded UI files | ncurses |
| Windows | Yes, though Linux and macOS are the main targets | No platform list; names MSVC as a compiler | Partial: MSYS2, MinGW and PDCurses, no MSVC build described |
| Linux and macOS | Yes | No platform list | Yes |
| Integration | CMake `FetchContent`; packages for vcpkg, Conan and others | Clones FTXUI into `external/` | Own CMake build |
| Stars and commits | 10.8k and 997 | 54 and 36, no releases | 3.6k and 191 |
| Approach | Components and layout | Qt-like widgets, `connect(...)`, JSON UI files | Immediate mode, from Dear ImGui |

Also read: [why TUIKit was built](https://medium.com/@sofiane.khelladi/why-i-built-tuikit-a-qt-inspired-terminal-ui-framework-for-scientific-applications-7ad1b3a9bafb)
(the page refused the automated read, so it is still unread).

- **FTXUI** is the first candidate: no dependencies, and it runs on the three platforms.
- **ImTui** doesn't fit today, because the project's Windows build is MSVC.
- **TUIKit** would bring its API closer to Qt, but it adds a young project on top of FTXUI. Using
  FTXUI directly should come first, unless its API turns out to be a problem.
- **Add, don't replace.** `ConsoleMenu` and the `tests/AppScenarios` tests read from redirected input,
  which a text-based UI makes harder. A new `apps/TuiApp` keeps them, and two frontends over the same
  layers show the architecture better.

Open questions:

- How is a text-based UI tested automatically?
- Which version of FTXUI can Conan 1 install?
- How much logic could it share with `ConsoleMenu`?

## IoT and low-power devices

| | [LVGL](https://github.com/lvgl/lvgl) | [Slint](https://slint.dev/pricing) |
|---|---|---|
| Language | C, compatible with C++ | C++ support not stated on the pricing page; to check |
| License | MIT. The separate LVGL Pro tool has paid tiers | GPLv3 for open source, or royalty-free for proprietary apps excluding embedded systems |
| Embedded | Included | Free for non-commercial, personal and open source projects; commercial devices pay from $1.00 each |
| Memory | At least 32 kB RAM and 128 kB flash; typical UI about 100 kB and 200-300 kB | Not stated on the pricing page |
| On a PC | SDL, X11 and Wayland simulator | To check |

- The first question isn't the library but the target. On a board with Linux, the layers should work
  as they are. On a small microcontroller, they use dynamic memory, `std::string` and exceptions,
  which may not fit. Finding out would be an interesting test of the architecture.
- A simulator allows trying it without buying hardware. Choose real hardware only if it is needed.
- The repository has no license file yet. Decide on one before relying on an "open source" condition.

## macOS

| Possible without a Mac | Not possible, or costs more |
|---|---|
| Build on GitHub's macOS runners | Try a graphical UI by hand |
| Run the tests and the console scenarios | Check how it looks and behaves on a real machine |
| | Sign and notarize the app, which needs an Apple developer account |

- **Cost:** in a private repository, a macOS minute costs $0.062, against $0.010 on Windows and $0.006
  on Linux ([billing](https://docs.github.com/en/billing/concepts/product-billing/github-actions)).
  Standard runners are free in public repositories. If it stays private, run the job by hand or before
  releases, not on every pull request.
- **Runners:** arm64 and Intel are both available
  ([labels](https://docs.github.com/en/actions/reference/runners/github-hosted-runners)).
- It needs the Linux work first: a build that isn't MSVC, and scripts that work outside Windows.

Open questions:

- Does the project build with Apple Clang, whose C++20 support differs from gcc's?
- Should the documentation state that macOS is "built and tested, not tried by hand"?

## Android

With [Qt for Android](https://doc.qt.io/qt-6/android.html) (Qt 6.12 documentation): Android 9 to 16,
arm64 and x86, Clang with NDK r27c, JDK 21, and multi-ABI packages only with CMake.

| Possible | Not possible, or costs more |
|---|---|
| Build in the CI with the NDK | Testing on many devices |
| Try the app on a real Android phone, at no cost | Publishing on Google Play, which has its own requirements |
| An emulator on Linux runners, which support hardware acceleration | |

- It depends on the Qt frontend (`v0.9.0`), and on that UI being usable on a small touch screen. QML
  may suit that better than Widgets: consider it when choosing between them.
- **Storage:** `orders.txt` is written in the current working directory, which doesn't fit Android.
- **License:** [Qt](https://doc.qt.io/qt-6/licensing.html) is available under the LGPL v3 if its terms
  can be met, and some modules only under the GPL v3. Read the
  [LGPL obligations](https://www.qt.io/licensing/open-source-lgpl-obligations) (not read yet), which
  matter more in a package for a phone.
- iOS has the limits of macOS, and needs an Apple account to install on a device.

## Order

None of these has a version yet. Some constraints:

- macOS needs `v0.6.0` (Linux); Android needs `v0.9.0` (Qt).
- The text-based UI is the cheapest to try: it needs no hardware or other operating system, so it could
  come before Qt if it proves useful.
