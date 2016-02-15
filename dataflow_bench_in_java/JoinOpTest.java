import static org.junit.Assert.*;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class JoinOpTest
{
    @Test
    public void DelegatesZero()
    {
        MockOp next = new MockOp();
        JoinOp to_test = new JoinOp(next);
        to_test.invoke(0);
        assertTrue(next.sawInvoke);
        assertEquals(next.saw, 0);
    }

    @Test
    public void DelegatesOne()
    {
        MockOp next = new MockOp();
        JoinOp to_test = new JoinOp(next);
        to_test.invoke(1);
        assertTrue(next.sawInvoke);
        assertEquals(next.saw, 1);
    }

    @Test
    public void IfZeroWasAdded_FiltersOutZero()
    {
        MockOp next = new MockOp();
        JoinOp to_test = new JoinOp(next);
        to_test.add(0);
        to_test.invoke(0);
        assertFalse(next.sawInvoke);
    }

    @Test
    public void IfZeroWasAdded_DelegatesOne()
    {
        MockOp next = new MockOp();
        JoinOp to_test = new JoinOp(next);
        to_test.add(0);
        to_test.invoke(1);
        assertTrue(next.sawInvoke);
        assertEquals(next.saw, 1);
    }

    @Test
    public void IfZeroWasAdded_DelegatesTwo()
    {
        MockOp next = new MockOp();
        JoinOp to_test = new JoinOp(next);
        to_test.add(0);
        to_test.invoke(2);
        assertTrue(next.sawInvoke);
        assertEquals(next.saw, 2);
    }

    @Test
    public void IfOneWasAdded_DelegatesZero()
    {
        MockOp next = new MockOp();
        JoinOp to_test = new JoinOp(next);
        to_test.add(1);
        to_test.invoke(0);
        assertTrue(next.sawInvoke);
        assertEquals(next.saw, 0);
    }
}
