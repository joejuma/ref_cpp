# Reference 'Factory' Implementation (C++)

## What is this?
A reference implementation of a Factory structure. This **is not the 
Gang of Four type of Factory**. In this sense, a Factory is an object 
which handles the creation, tracking and deletion of a given type of 
object. This implementation is for C++ as single-header template with 
dependencies on the standard library.

## Usage
### Setup
1. Grab `Factory_struct.h`
2. Add it to your project.
3. `#include "Factory_struct.h"`
4. `Factory<YourType> yourFactory;`

### Creating an Element
`YourType* ptr = yourFactory.create();` or `YourType* ptr = 
yourFactory.create(someValue);`

### Finding an Element
`yourFactory.find(ptr);` or `yourFactory.getIndex(ptr);`

### Accessing an Element in the Factory Roster
`yourFactory[index];`

### Deleting an Element
`yourFactory.destroy(index);` or `yourFactory.destroy(ptr);`

## To-Do
1. Dependency injection for memory operations should be an option for this structure, so that memory layout can be managed by a structure with a distinct responsibility.
2. Object pooling rather than dynamic fragmented allocation with pointer storage should be the behavior of this ideally.

## License (Simplified)
This is under the MIT license.
1. There is 0 liability if you choose to use this.
2. You can freely use this, mod it, remix it, whatever you want.
3. You don't have to give me credit, but it would be appreciated.
4. Don't try to construe I'm affiliated with or endorse you just because 
you're using this code.
5. Have fun. Okay, I'll come clean - that's not in the normal license, 
but you still should.

## License (Full)
Copyright 2023, Joseph Juma.

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

## Authors
Joseph Juma
