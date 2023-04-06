# hintdump

Display the default hints for a file system.

MPI-IO uses "hints" as ways for users to tell the MPI-IO routines something
about the anticipated workload.  MPI-IO implementations use hints to tune
internal algorithms.  In practice, not many users set hints but they can have a
big impact on perfromamce sometimes.

This simple little utility has been way more useful than I expected.  Knowing
something about the default hints also helps confirm my own assumptions about
what's going on inside the MPI-IO library.

## usage

    hintdump <filename>

`<filename>` can be a directory
