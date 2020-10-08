
#include <Wire.h>

// my I2C LCD uses this library but the ideas should be the same.
#include "rgb_lcd.h"

rgb_lcd lcd;

#define GRAPH_SIZE 20
char graphData[GRAPH_SIZE] = {0}; // Array of 20 data elements to build our graph.  Initialized to zero

// this function simply puts a new data element into the graphData array.
// it moves the old data one position over to make room for the new data.
void addData(char theData)
{
  // step 1: move all the data points down to accept the new data point
  for(int x=1;x<GRAPH_SIZE;x++)
  {
    graphData[x-1] = graphData[x];
  }
  // step 2: put the new data point at the end of the graph
  graphData[GRAPH_SIZE-1] = theData;
}

// this function accepts an array for the character and an array of 5 data elements
// it fills the character with a custom image based upon the 5 data elements.
void draw5bars(char character[8], char bar[5])
{
  // first create some masks to represent a 1 in each of the 5 columns.
  const char pixelMasks[] = {0b10000,0b01000,0b00100,0b00010,0b00001};

  char outputMask = 0;

  for(int x = 0;x<8;x++) // step through the rows.  We are building the custom character row by row
  {
    outputMask = 0;
    for(int y=0;y<5;y++)
    {
      if(bar[y] >= 8-x)
      {
        outputMask |= pixelMasks[y];
      }    
    }
    character[x] = outputMask;
  }
}

void setup() {

    lcd.begin(16, 2);
    lcd.setCursor(0,0);
    lcd.print("Graph Demo");
    lcd.setCursor(0, 1);
    lcd.write((unsigned char)0); // predraw the 4 custom characters needed for the graph.
    lcd.write((unsigned char)1); // we will continuously redefine each character so we never need
    lcd.write((unsigned char)2); // to redraw each character.  Just change the definition.
    lcd.write((unsigned char)3);
}

void loop() {
  char data = random(0,9); // get a random data point between 0 & 7
  char character[8] = {0};
  addData(data);

  // modify each custom character based upon the data in the graph
  // with 20 data points in the graphData, and 5 columns in each custom character
  // we need 4 custom characters to draw all the data.
  draw5bars(character,&graphData[0]);
  lcd.createChar(0,character);

  // the & means use the MEMORY ADDRESS of this information.
  // an array in C is represented by the MEMORY ADDRESS of the first element
  // draw5bars needs an array of 5 data points so we will pass the address of
  // the 0'th, 5'th, 10'th, and 15'th data point.  draw5bars will see these as 5 element arrays.
  draw5bars(character,&graphData[5]);
  lcd.createChar(1,character);
  
  draw5bars(character,&graphData[10]);
  lcd.createChar(2,character);
  
  draw5bars(character,&graphData[15]);
  lcd.createChar(3,character);

  // draw the most recent data point after the graph
  lcd.setCursor(6,1);
  lcd.print((int)data);

  // my LCD has an RGB backlight so I will adjust it based upon the data.
  if(data > 6)
  {
    lcd.setRGB(255,0,0);
  }
  else if(data > 4)
  {
    lcd.setRGB(255,255,0);
  }
  else
  {
    lcd.setRGB(0,255,0);
  }  
  delay(200);
}
