#! /bin/bash

pushd $(dirname $0)

if test -d ../.git ; then

# because GIT will report the SH script as 'in use' ...
echo "ignore this error line when it occurs after a while:"
echo "  error: unable to unlink old 'utils/mk-git-svn-clone.sh' (Text file busy)"

git checkout svn --force
git svn fetch
git checkout master --force
git pull --all

else

git svn init https://utfcpp.svn.sourceforge.net/svnroot/utfcpp
git svn fetch
git branch --track svn remotes/git-svn

echo <<EOT
Also run:
  git clone git@github.com:GerHobbelt/utfcpp.sourceforge.net.git
in another (temporary) directory and edit the .git/config to look
like:

[core]
	repositoryformatversion = 0
	filemode = false
	bare = false
	logallrefupdates = true
	symlinks = false
	ignorecase = true
[svn-remote "svn"]
	url = https://utfcpp.svn.sourceforge.net/svnroot/utfcpp
	fetch = :refs/remotes/git-svn
[branch "svn"]
	remote = .
	merge = refs/remotes/git-svn
[remote "origin"]
	fetch = +refs/heads/*:refs/remotes/origin/*
	url = git@github.com:GerHobbelt/utfcpp.sourceforge.net.git
[branch "master"]
	remote = origin
	merge = refs/heads/master

and run
  git remote update
  git checkout master
  git pull
to load the github state of affairs.

Sync the SVN repo by running
  git checkout svn
  git svn fetch

and possibly merge SVN updates into the 'master' branch.
EOT

fi

popd

