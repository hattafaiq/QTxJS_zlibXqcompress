# QTxJS_zlibXqcompress
<ul>
<li>simulasi kompresi internal qt to zlib </li>
LZ77 compression <br/>
DEFLATE Compressed Data Format Specification <br/>
<pre>
......................    /\..............Symbol    Code  
                         0  1             ------    ----  
                        /    \                A      00   
                       /\     B               B       1   
                      0  1                    C     011   
                     /    \                   D     010   
                    A     /\                              
                         0  1                             
                        /    \                            
                       D      C                           
                                                          
</pre>
<li>https://datatracker.ietf.org/doc/html/rfc1951         </li>    
<li>isinya rfc1951 kalau di js minta dipotong 4byte baru bisa di deflation </li>
  0   1   2   3   4... <br/>
  +---+---+---+---+================================+ <br/>
  |  LEN  | NLEN  |... LEN bytes of literal data...| <br/>
  +---+---+---+---+================================+ <br/>

</ul>
