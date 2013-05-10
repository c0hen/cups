//========================================================================
//
// FontEncoding.h
//
// Copyright 1999 Derek B. Noonburg
//
//========================================================================

#ifndef FONTENCODING_H
#define FONTENCODING_H

#ifdef __GNUC__
#pragma interface
#endif

#include "gtypes.h"

//------------------------------------------------------------------------
// FontEncoding
//------------------------------------------------------------------------

#define fontEncHashSize 419

class FontEncoding {
public:

  // Construct an empty encoding.
  FontEncoding();

  // Construct an encoding from an array of char names.
  FontEncoding(const char **encoding, int size);

  // Destructor.
  ~FontEncoding();

  // Create a copy of the encoding.
  FontEncoding *copy() { return new FontEncoding(this); }

  // Return number of codes in encoding, i.e., max code + 1.
  int getSize() { return size; }

  // Add a char to the encoding.
  void addChar(int code, const char *name);

  // Return the character name associated with <code>.
  const char *getCharName(int code) { return encoding[code]; }

  // Return the code associated with <name>.
  int getCharCode(const char *name);

private:

  FontEncoding(FontEncoding *fontEnc);
  int hash(const char *name);
  void addChar1(int code, const char *name);

  const char **encoding;	// code --> name mapping
  int size;			// number of codes
  GBool freeEnc;		// should we free the encoding array?
  short				// name --> code hash table
    hashTab[fontEncHashSize];
};

#endif