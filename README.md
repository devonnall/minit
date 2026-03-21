# Minit: A Mini Clone of Git

**Status**: Early development

Minit will be a clone of Git with basic functionalities covered. Those include:

- minit add: move files to staging area
- minit rm: remove files from staging area
- minit commit: create a snapshot from staged files of the project
- minit checkout: create and switch between branches
- ...and more

## Current Progress

As of March 21, 2026, I have written the logic required to read the contents of a file, prepend the contents with a header (e.g. blob <size>\0), and compute the SHA1 hash. A series of tests have been written that verify the hashes my program creates vs the hash Git produces (verified against `git hash-object <filename>`). 

The next logical step is to start implementing the ability to stage files (`minit add`). This would take the file, compute the SHA1 of the object, and add it ./minit/objects and to the index in ./minit/index. This index will be used to create a commit object and tree objects later on after using `minit commit`. 


