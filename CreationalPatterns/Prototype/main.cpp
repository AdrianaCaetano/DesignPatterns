#include <iostream>

using namespace std;

enum imageType
{
  LSAT, SPOT
};

// like out Graphic Class on the slides example
class Image
{
  public:
    virtual void draw() = 0;
    static Image *findAndClone(imageType);
  protected:
    virtual imageType returnType() = 0;
    virtual Image *clone() = 0; // special method called clone, virtual has to be implemented in child classes
    // As each subclass of Image is declared, it registers its prototype
    static void addPrototype(Image *image) // allow adding prototypes and know how many were created
    {
        _prototypes[_nextSlot++] = image; //add to the list
    }
  private:
    // addPrototype() saves each registered prototype here
    static Image *_prototypes[10]; //list of prototypes //registering different types of images it supports, at most 10 
    static int _nextSlot;
};

Image *Image::_prototypes[]; //an array that supports 10 different types of images and saves all prototypes it can support
int Image::_nextSlot;

// Client calls this public static member function when it needs an instance
// of an Image subclass
Image *Image::findAndClone(imageType type)
{
  for (int i = 0; i < _nextSlot; i++)
    if (_prototypes[i]->returnType() == type) //if this class exists
      return _prototypes[i]->clone(); // return a new instance of this type // if corresponding class of this type exists, clone it
  return NULL;
}

// derived class from image that implements clone method 
class LandSatImage: public Image
{
  public:
    imageType returnType()
    {
        return LSAT;
    }
    void draw()
    {
        std::cout << "LandSatImage::draw " << _id << std::endl;
    }
    // When clone() is called, call the one-argument ctor with a dummy arg
    Image *clone() //does not return the prototype itself, it returns a new instance of this class
    {
        return new LandSatImage(1); //creates a new instance of this class and return this, don't use default constructor
    }
  protected:
    // This is only called from clone()
    LandSatImage(int dummy)
    {
        _id = _count++; //records how many instances have been created
    }
  private:
    // Mechanism for initializing an Image subclass - this causes the
    // default ctor to be called, which registers the subclass's prototype
    static LandSatImage _landSatImage; //static variable 
    // This is only called when the private static data member is initiated // it's declared inside the class, but has to be defined outside the class (C++)
    LandSatImage() //default constructor
    {
        addPrototype(this); //add this instance, register this prototype from methid defined in parent class
    }
    // Nominal "state" per instance mechanism
    int _id;
    static int _count;
};

// Register an instance of the subclass as a prototype // declare this variable globally to hold the value/count for every constructor execution
LandSatImage LandSatImage::_landSatImage; //related to prototype class // whenever this is executed, the default constructor is called
// Initialize the "state" per instance mechanism
int LandSatImage::_count = 1; //this is one because the line about have created one isntance already

class SpotImage: public Image
{
  public:
    imageType returnType()
    {
        return SPOT;
    }
    void draw()
    {
        std::cout << "SpotImage::draw " << _id << std::endl;
    }
    Image *clone() // fundamental method on Prototype DP
    {
        return new SpotImage(1);
    }
  protected:
    SpotImage(int dummy)
    {
        _id = _count++;
    }
  private:
    SpotImage()
    {
        addPrototype(this);
    }
    static SpotImage _spotImage;
    int _id;
    static int _count;
};

SpotImage SpotImage::_spotImage;
int SpotImage::_count = 1;

// Simulated stream of creation requests with different image types that need differnt prototypes
const int NUM_IMAGES = 8;
imageType input[NUM_IMAGES] = // diferent types of images
{
  LSAT, LSAT, LSAT, SPOT, LSAT, SPOT, SPOT, LSAT //8 different images
};

//client
int main()
{
  // want to create ptototypes of different images
  Image *images[NUM_IMAGES]; //define a list of different images (don't mention the classes names of different types of images) // create the images and populate this array

  // Given an image type, find the right prototype, and return a clone
  for (int i = 0; i < NUM_IMAGES; i++)
    images[i] = Image::findAndClone(input[i]); //get an instance of the corresponding image, in the end it will have 8 different instances of the correpsonding classes

  // Demonstrate that correct image objects have been cloned
  for (int i = 0; i < NUM_IMAGES; i++)
    images[i]->draw(); //call the corresponding draw method to validate/check the type and id

  // Free the dynamic memory
  for (int i = 0; i < NUM_IMAGES; i++)
    delete images[i];
}
