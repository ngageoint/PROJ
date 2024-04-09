Pod::Spec.new do |s|
  s.name    = "PROJ-include"
  s.version = "9.4.0"
  s.summary = "PROJ coordinate transformation software library."
  s.description = <<-DESC
PROJ is a generic coordinate transformation software that transforms geospatial coordinates from one coordinate reference system (CRS) to another. This includes cartographic projections as well as geodetic transformations. PROJ is released under the X/MIT open source license

PROJ includes command line applications for easy conversion of coordinates from text files or directly from user input. In addition to the command line utilities PROJ also exposes an application programming interface, or API in short. The API lets developers use the functionality of PROJ in their own software without having to implement similar functionality themselves.

PROJ started purely as a cartography application letting users convert geodetic coordinates into projected coordinates using a number of different cartographic projections. Over the years, as the need has become apparent, support for datum shifts has slowly worked its way into PROJ as well. Today PROJ supports more than a hundred different map projections and can transform coordinates between datums using all but the most obscure geodetic techniques.
  DESC
  s.homepage = "https://proj.org/"
  s.license = { :type => "MIT",
                :file => "COPYING" }
  s.author  = 'PROJ contributors', 'Open Source Geospatial Foundation'
  s.source  = { :git => "https://github.com/ngageoint/PROJ.git", :tag => s.version.to_s }

  s.platforms = { :ios => "12.0", :osx => "10.13", :watchos => "4.0", :tvos => "12.0" }

  s.source_files = 'include/**/*.hpp'

end
