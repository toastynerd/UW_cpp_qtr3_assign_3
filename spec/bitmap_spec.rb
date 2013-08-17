#bitmap_spec.rb

require 'bitmap'


describe Bitmap do

  it "Should create a valid WindowsBitmapHeader" do
    header = Bitmap::WindowsBitmapHeader.new
    expect(header).to be_valid
  end
end
