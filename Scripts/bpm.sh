#!/bin/sh

if [[ "$1" == "init" ]]; then
    python3 -c "import bpm;bpm.init('$2')"
    exit 0
fi
if [[ "$1" == "register" ]]; then
    python3 -c "import bpm;bpm.register('$2', '$3')"94
    exit 0
fi
if [[ "$1" == "unregister" ]]; then
    python3 -c "import bpm;bpm.unregister('$2')"
    exit 0
fi
if [[ "$1" == "install" ]]; then
    python3 -c "import bpm;bpm.install('$2')"
    exit 0
fi
if [[ "$1" == "uninstall" ]]; then
    python3 -c "import bpm;bpm.uninstall('$2')"
    exit 0
fi
if [[ "$1" == "search" ]]; then
    python3 -c "import bpm;bpm.print_search('$2')"
    exit 0
fi