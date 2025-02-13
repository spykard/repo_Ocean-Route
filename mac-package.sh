#!/usr/bin/env bash

# Creates packages from and already built application and data
# Produces a ZIP-ball if zip is available in $PATH and .pkg if Packages tool is available (https://github.com/packagesdev/packages)

if which macdeployqt >/dev/null; then
  DEPLOY='macdeployqt'
elif [ -f /usr/local/opt/qt5/bin/macdeployqt ]; then
  DEPLOY='/usr/local/opt/qt5/bin/macdeployqt'
else
  DEPLOY="$(find ~/Qt -name macdeployqt|head -n1)"
fi
if [ -z "$DEPLOY" ]; then
  echo "Tool macdeployqt not found, can't continue"
  exit 1
fi
$DEPLOY Weathergrib.app
rm -rf data/config
if which zip >/dev/null; then
  echo "ZIP found, creating Weathergrib-mac.zip"
  zip -r Weathergrib-mac.zip Weathergrib.app data > /dev/null
fi
if which packagesbuild >/dev/null; then
  echo "Packages found, creating Weathergrib-mac.pkg"
  packagesbuild mac-installer/Weathergrib.pkgproj
  mv mac-installer/build/Weathergrib.pkg Weathergrib-mac.pkg
fi
