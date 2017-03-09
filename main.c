#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"
#include "parser.h"

int main(int argc, char **argv) {

  screen s;
  color color;
  int r, c;
  color.red = MAX_COLOR;
  color.green = MAX_COLOR;
  color.blue = MAX_COLOR;

  struct matrix * edges;
  struct matrix * transform;

  edges = new_matrix(4, 4);
  transform = new_matrix(4, 4);

  /* if ( argc == 2 ) */
  /*   parse_file( argv[1], transform, edges, s ); */
  /* else */
  /*   parse_file( "stdin", transform, edges, s ); */
  
  clear_screen(s); 

    edges->lastcol = 0;

  for(r=0;r<4;r++){
    for(c=0;c<4;c++){
      edges->m[r][c] = 0.0;
    }
  }

  /* add_edge(edges, 250, 250, 0, 250, 500, 0); */
  /* printf("Printing matrix after adding 2 points\n"); */
  /* print_matrix(edges); */
  /* add_edge(edges, 250, 250, 0, 375, 500, 0); */
  /* printf("Printing matrix after adding 4 points. Matrix should have grown.\n"); */
  /* print_matrix(edges); */
  /* add_edge(edges, 250, 250, 0, 500, 500, 0); */
  /* printf("Printing matrix after adding 6 points\n"); */
  /* print_matrix(edges); */
  /* add_edge(edges, 250, 250, 0, 500, 375, 0); */
  /* add_edge(edges, 250, 250, 0, 500, 250, 0); */
  /* add_edge(edges, 250, 250, 0, 500, 125, 0); */
  /* add_edge(edges, 250, 250, 0, 500, 0, 0); */
  /* add_edge(edges, 250, 250, 0, 375, 0, 0); */
  /* add_edge(edges, 250, 250, 0, 250, 0, 0); */
  /* add_edge(edges, 250, 250, 0, 125, 0, 0); */
  /* add_edge(edges, 250, 250, 0, 0, 0, 0); */
  /* add_edge(edges, 250, 250, 0, 0, 125, 0); */
  /* add_edge(edges, 250, 250, 0, 0, 250, 0); */
  /* add_edge(edges, 250, 250, 0, 0, 375, 0); */
  /* add_edge(edges, 250, 250, 0, 0, 500, 0); */
  /* add_edge(edges, 250, 250, 0, 125, 500, 0); */

  /* transform = make_scale(0.5, 0.5, 0.5); */

  /* matrix_mult(transform, edges); */
  /* printf("New\n\n");  */
  /* /\* matrix_mult(make_translate(100, 100, 100), edges); *\/ */

  /* transform = make_translate(125, 125, 0); */

  /* printf("New\n\n"); */
  /* fflush(stdout); */
  /* matrix_mult(transform, edges); */
  /* print_matrix(edges); */
  /* draw_lines(edges, s, color); */



  /* transform = make_rotZ(45/4.0); */
  
  /* int k; */
  /* for(k=0;k<32;k++){ */
  /*   add_edge(edges,0,0,0,250,0,0); */
  /*   matrix_mult(transform, edges); */
  /* } */
  
  /* print_matrix(edges); */
  /* printf("\n"); */
  /* print_matrix(edges); */
  /* transform = make_translate(250, 250, 0); */
  /* matrix_mult(transform, edges); */
  /* transform = make_rotY(45.0); */
  /* matrix_mult(transform, edges); */


  /* add_edge(edges,0,0,0,100,0,0); */
  /* add_edge(edges,100,0,0,100,100,0); */
  /* add_edge(edges,100,100,0,0,100,0);   */
  /* add_edge(edges,0,100,0,0,0,0); */
  /* add_edge(edges,0,0,100,100,0,100); */
  /* add_edge(edges,100,0,100,100,100,100); */
  /* add_edge(edges,100,100,100,0,100,100); */
  /* add_edge(edges,0,100,100,0,0,100); */
  /* add_edge(edges,0,0,0,0,0,100); */
  /* add_edge(edges,0,100,0,0,100,100); */
  /* add_edge(edges,100,100,0,100,100,100); */
  /* add_edge(edges,100,0,0,100,0,100); */

  /* clear_screen(s); */
  /* draw_lines(edges, s, color); */
  /* display(s); */
  
  /* transform = make_translate(100,100,0); */
  /* matrix_mult(transform, edges); */

  /* clear_screen(s); */
  /* draw_lines(edges, s, color); */
  /* display(s); */
  
  /* transform = make_rotX(25.0); */
  /* matrix_mult(transform, edges); */

  /* clear_screen(s); */
  /* draw_lines(edges, s, color); */
  /* display(s); */
  
  /* transform = make_rotY(25.0); */
  /* matrix_mult(transform, edges); */

  /* clear_screen(s); */
  /* draw_lines(edges, s, color); */
  /* display(s); */
  
  /* transform = make_rotZ(25.0); */
  /* matrix_mult(transform, edges); */

  
  /* printf("New\n\n"); */
  /* fflush(stdout); */

  parse_file("script", transform, edges, s);

  clear_screen(s);
  draw_lines(edges, s, color);
  display(s);
  save_extension(s, "transform.png");
  
  free_matrix( edges );
  free_matrix( transform );
}  
