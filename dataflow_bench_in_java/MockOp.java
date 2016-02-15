public class MockOp implements OpInterface
{
    public boolean sawInvoke = false;
    public int saw;
    
    public void invoke(int incoming)
    {
        sawInvoke = true;
        saw = incoming;
    }
}
