import static org.junit.Assert.*;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class PredicateOpTest
{
    @Test
    public void IfPredicateIsZero_FiltersOutZero()
    {
        MockOp next = new MockOp();
        PredicateOp to_test = new PredicateOp(0, next);
        to_test.invoke(0);
        assertFalse(next.sawInvoke);
    }

    @Test
    public void IfPredicateIsZero_DelegatesOne()
    {
        MockOp next = new MockOp();
        PredicateOp to_test = new PredicateOp(0, next);
        to_test.invoke(1);
        assertTrue(next.sawInvoke);
        assertEquals(next.saw, 1);
    }

    @Test
    public void IfPredicateIsZero_DelegatesTwo()
    {
        MockOp next = new MockOp();
        PredicateOp to_test = new PredicateOp(0, next);
        to_test.invoke(2);
        assertTrue(next.sawInvoke);
        assertEquals(next.saw, 2);
    }

    @Test
    public void IfPredicateIsOne_DelegatesZero()
    {
        MockOp next = new MockOp();
        PredicateOp to_test = new PredicateOp(1, next);
        to_test.invoke(0);
        assertTrue(next.sawInvoke);
        assertEquals(next.saw, 0);
    }
}
