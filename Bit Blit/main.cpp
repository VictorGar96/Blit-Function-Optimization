//
//  main.cpp
//  Bit Blit
//
//  Created by Victor Garcia Cortes on 08/11/2019.
//  Copyright © 2019 VictorGarciaCortes. All rights reserved.
//

// Bit blit, which stands for Bit Block Transfer, is a data operation commonly used computer graphics in which several bitmaps are combined into one using a boolean function.

// This operation envolves at least two bitmap, one source and one destination. The pixels of each are combined in the destination.

#include <iostream>
#include <cstdint>

typedef uint16_t Rgb565;

void Blit
(
    Rgb565 * target,
    unsigned target_width,
    unsigned target_x,
    unsigned target_y,
    Rgb565 * source,
    unsigned source_width,
    unsigned source_height
)
{
    unsigned delta = target_width - source_width;
    target += target_width * target_y + target_x;
    Rgb565* source_end = source;
    
    // Recorremos el alto
    while(source_height--) // Sale del bucle en caso de que source_height sea == 0 (false)
    {
        source_end += source_width;
        // Recorremos el ancho
        while(source < source_end)
        {
            *target++ = *source++;
        }
        target += delta;
    }
}

int main(int argc, const char * argv[])
{
    const unsigned display_width  = 800;
    const unsigned display_heigth = 600;
    
    Rgb565 display_buffer[display_width * display_heigth];
    
    const unsigned texture_width  = 128;
    const unsigned texture_height = 128;
    
    Rgb565 texture[texture_width * texture_height];
    
    Blit
    (
        display_buffer,  // puntero al buffer de la ventana
        display_width,   // ancho de la ventana
        100,             // coordenada x de la ventana en la que se hará el blit
        100,             // coordenada y de la ventana en la que se hará el blit
        texture,         // puntero al buffer de la textura
        texture_width,
        texture_height
     );
    
    
    return 0;
}
