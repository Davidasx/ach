# ach

Atcoder Commandline Helper

# Requirements

[python](https://www.python.org/)

[node.js](https://nodejs.org)

[cf-tool](https://github.com/xalanq/cf-tool)  (for testing code,please configure templates before installation)

# Installation

1.Install [online-judge-tools](https://github.com/online-judge-tools/oj).

```
pip3 install online-judge-tools
```

2.Install [atcoder-cli](https://github.com/Tatamo/atcoder-cli).

```
npm install -g atcoder-cli
```

3.Download latest version from release page.

4.Run:

```
ach init
```

Everything will be configured for you!

Note:If you can't run it,please put it in a directory that supports PATH,like C:\WINDOWS\system32 for Windows and /usr/bin for Linux.

# Usage

Just run:

```
ach
```

The following info will show up:
```
Atcoder Commandline Helper(ach) v1.0
If you've never used this before,please run `ach init`
Usage:
ach submit [OJOPTIONS]:submit a task
ach test:test program under current directory
ach race [CONTESTID]:open a contest,generate templates and open programs
ach stand [CONTESTID]:open standings page
ach list [CONTESTID]:show problem info
ach init:initialize templates and login
```
