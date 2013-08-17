#binary_spec.rb

require 'Binary'

describe Binary do

  it "should be able to make a Byte" do
    byte1 = Binary::Byte.new
    epect(byte1).to be_valid
  end

  it "should be able to make a Word" do
    word1 = Binary::Word.new
    expect(word1).to be_valid
  end

  it "should be able to make a DoubleWord" do
    dword1 = Binary::DoubleWord.new
    expect(dword1).to be_valid
  end

end
