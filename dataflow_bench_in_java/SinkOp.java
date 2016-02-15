import java.util.Collection;
import java.util.ArrayList;

public class SinkOp implements OpInterface
{
    Collection<Integer> list;

    public SinkOp()
    {
        list = new ArrayList<Integer>();
    }

    public void invoke(int incoming)
    {
        list.add(incoming);
    }
}
