# Adding operation
    C++ interact with operations generated by TableGen
        **The operation name**
        **The traits of the operation** this allow you to specitfy traits(特性) of the operation， 例如 是否 有side effects 或者 它是否应该查验操作数和结果的类型是相同的
        **The arguments of the operation**  input operands  
        ** The result of the operation ** This includes a one-line summary as wel as a longer human-readable description of the operation.
        ** Dialect specifi information **  Additional information could be added to the operation definition that are only used by dialect specific drivers. These are ignored by the main op and doc generators, but could be used in, say, the translation from a dialect to another representation.



# Adding parttens （什么是 pattern ？）
    DAG Tile to DAG Tile rewrite 
    Parttens provide a concise(简洁的) way to express this transformation as a pair of source pattern to match and resultant pattern
    There are both the C++ classes to represent this transformation, as well as the patterns in TableGen from which these can be generated.  

# TableGen Patterns
  
