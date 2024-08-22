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

## Hints file

This utility also ends up being an easy way to verify you've set up your "romio
hints" file correctly (see
https://wordpress.cels.anl.gov/romio/2008/09/26/system-hints-hints-via-config-file/)

## Platforms

Since each HPC platform is slightly different with respect to job schedulers
and queues, I started collecting the submission scripts from various machines
in the `platform` directory.
