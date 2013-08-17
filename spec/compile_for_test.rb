#! /usr/bin/env ruby
require 'mkmf'

file = ARGV.first 

`swig -c++ -ruby #{file}.i`
create_makefile(file)
`make`

puts `rspec spec/#{file}_spec.rb`
