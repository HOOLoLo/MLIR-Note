# Operation pass

MLIR 中所有 的 passes 继承自 OperationPass 然后 受下面的限制。

any noncompliance will lead to problematic behavior in multithreaded and other advanved scenarios:

Modify any state referenced 
修改了 任何 state referenced 或者 relied upon 外部的 

