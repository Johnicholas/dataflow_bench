public class Benchmark
{
    private SinkOp s;
    private PredicateOp p4;
    private PredicateOp p6;
    private JoinOp j1;
    private PredicateOp p8;
    private PredicateOp p10;
    private JoinOp j2;
    
    public Benchmark()
    {
        s = new SinkOp();
        p4 = new PredicateOp(4, s);
        p6 = new PredicateOp(6, p4);
        j1 = new JoinOp(p6);
        p8 = new PredicateOp(8, j1);
        p10 = new PredicateOp(10, p8);
        j2 = new JoinOp(p10);
        for (int i = 0; i < 12000; i += 1) {
            if (i % 2 == 0) {
                j1.add(i);
                j2.add(i);
            }
        }
    }

    public void run()
    {
        for (int i = 0; i < 2*1000*1000; i += 1) {
            if (i%2 == 1) {
                j2.invoke(i);
            }
        }
    }
}
