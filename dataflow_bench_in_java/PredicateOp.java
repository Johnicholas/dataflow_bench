public class PredicateOp implements OpInterface
{
    private int predicate;
    private OpInterface next;
    
    // Constructor
    public PredicateOp(int predicate, OpInterface next)
    {
        this.predicate = predicate;
        this.next = next;
    }
    
    @Override
    public void invoke(int incoming)
    {
        if (incoming != predicate) {
            next.invoke(incoming);
        }
    }
}
