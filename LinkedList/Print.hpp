template <typename NodeType>
void Print(const typename NodeType::Ptr& head, std::ostream& out)
{
    auto node = head;
    while (node != nullptr)
    {
        out << node->data << " ";
        node = node->next;
    }
    out << std::endl;
}
