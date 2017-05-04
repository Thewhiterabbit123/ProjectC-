class Car {
	private:
		b2Body* m_body;
        std::vector<TDTire*> m_tires;
        b2RevoluteJoint *flJoint, *frJoint;
	public:
		Car();
		~Car();

		void update(int controlState);
	
};