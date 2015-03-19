A managed .Net wrapper for Ageia's PhysX written in C++/CLI for use by .Net applications.

Any bugs, suspected bugs or feature requests should go in the 'Issues' area of this project, if you need any help using the wrapper or have any issues with getting it working, post in the Discussion Group linked on the right.

Snapshots of the SVN will be made when a new feature is wrapped or a significant change has been made that warrants a snapshot being made, these are available under 'Downloads'. To keep fully up-to-date, you can check out the latest code from the SVN repository.

## PhysX 2.8.0 ##

I've decided that it's unnecessary to migrate the wrapper to 2.8.0 until such a time that a feature from 2.8.0 is needed. Anyone installed the 2.8.0 SDK or Drivers has full backwards compatibility with 2.7.3, but you'll just not be able to use any of the new functionality in 2.8.

## News ##

25th February: Fixed a bug in the earlier snapshot, 25\_02\_2008 B is now the latest snapshot.

25th February: Added a Daily Snapshot including the work on Description classes, and several lessons.

**Note:** A breaking change was made to the way JointDescriptions work, set\_Actor() is no longer required and is replaced by an array of Actors. If any functionality is now missing or broken, post an issue on the Issues area, thanks.

### Currently Working On: ###

**amiles:** Nothing.

**michael:** Unknown.


### Recently finished: ###

**amiles:** Migrating Description classes to managed code. Lessons 207, 208, 210, 213 and 215. Finished and tested the joint types that were already in the library.