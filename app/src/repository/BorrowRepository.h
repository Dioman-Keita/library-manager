class IBorrowRepository {
public:
    virtual ~IBorrowRepository() = default;

    // Les fonctions virtuelles pures restent inchangées (elles n'ont jamais de corps)
    virtual BookStatus check_availability(const std::string& book_id) const = 0;
    virtual void save_borrow(const Borrow& borrow) = 0;
    virtual std::optional<Borrow> find_active_borrow(const std::string& user_id, const std::string& book_id) const = 0;
    virtual void update_borrow(const Borrow& borrow) = 0;
    virtual std::vector<Borrow> find_by_user(const std::string& user_id) const = 0;
};