////
//// Created by Frylock Maryam on 10/10/21.
////
//
//
//
//
///* In TBM function variable u memorizes the length of the suffix
//  matched during  the previous attempt and the variable v
//   memorizes the length of the suffix  during the current attempt
//*/
//
///* Preprocessing of the Bad Character function shift */
//void PRE_BC( char *x, int m, int bm_bc[] ) {
//    int a, j;
//
//    for ( a=0; a < ASIZE; a++ ) bm_bc[ a ] = m;
//    for ( j=0; j < m-1;  j++ ) bm_bc[ x[ j ] ] = m - j - 1;
//}
//
///* Preprocessing of the Good Suffix function shift  */
//void PRE_GS( char *x, int m,  int bm_gs[] ) {
//    int i, j, p, f[XSIZE];
//
//    memset( bm_gs, 0, ( m + 1 ) * sizeof( int ) );
//    f[ m ] = j = m + 1;
//    for (i=m; i > 0; i-- ) {
//        while ( j <= m && x[ i - 1 ] != x[ j - 1 ] ) {
//            if ( bm_gs[ j ] == 0 ) bm_gs[ j ] = j - 1;
//            j = f[ j ];
//        }
//        f[ i - 1 ] = --j;
//    }
//    p=f[ 0 ];
//    for ( j=0; j <= m; ++j ) {
//        if ( bm_gs[ j ] == 0 ) bm_gs[ j ] = p;
//        if ( j == p ) p = f[ p ];
//    }
//}
//
///* Boyer-Moore string matching algorithm */
//void TBM( char *x, char *y, int n, int m ) {
//    int i, j, u, shift, v, turbo_shift, bm_gs[XSIZE], bm_bc[ASIZE];
//
//    /* Preprocessing */
//    PRE_GS( x, m, bm_gs );
//    PRE_BC( x, m, bm_bc );
//
//    i = u = 0;
//    shift = m;
//    while ( i <= n-m ) {
//        j = m - 1;
//        while ( j >= 0 && x[ j ] == y[ i + j ] ) {
//            --j;
//            if ( u != 0 && j == m - 1 - shift ) j -= u;
//        }
//        if ( j < 0 ) {
//            OUTPUT( i );
//            shift = bm_gs[ 0 ];
//            u = m - shift;
//        }
//        else {
//            v = m - 1 - j;
//            turbo_shift = u - v;
//            bc_shift = bm_bc[ y[ i+j ] ] - m + j + 1;
//            shift = MAX ( turbo_shift, bc_shift );
//            shift = MAX ( shift, bm_gs[ j+1 ] );
//            if ( shift == bm_gs[ j+1 ]) u = MIN( (m - shift), v );
//            else {
//                if ( turbo_shift < bc_shift ) shift = MAX (shift, (u+1) );
//                u = 0;
//            }
//        }
//        i += shift;
//    }
//}