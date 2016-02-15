import java.util.Set;
import java.util.HashSet;

public class JoinOp implements OpInterface
{
    private OpInterface next;
    private Set<Integer> table;
    
    // Constructor
    public JoinOp(OpInterface next)
    {
        this.next = next;
        this.table = new HashSet<Integer>();
    }

    // Mutator
    public void add(int to_add)
    {
        this.table.add(to_add);
    }
    
    @Override
    public void invoke(int incoming)
    {
        if (!this.table.contains(incoming)) {
            next.invoke(incoming);
        }
    }
}
