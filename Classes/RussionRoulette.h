#pragma once

namespace xophiix
{
	namespace algorithm
	{
		/**		
		simple RussionRoulette rules
		*/
		class RussionRoulette
		{
		public:
			RussionRoulette( unsigned bulletAllowed = DEFAULT_BULLET_COUNT )
			{
				m_bulletAllowed = bulletAllowed;
				reset();
			}

			unsigned getBulletAllowed() const
			{
				return m_bulletAllowed;
			}

			void setBulletAllowed( unsigned value )
			{
				m_bulletAllowed = value;
			}

			unsigned getSurviveCount() const
			{
				return m_suviveCount;
			}

			void reset()
			{
				for ( unsigned i = 0; i < BULLET_SLOT_COUNT; ++i )
				{
					m_slot[i] = false;
				}

				unsigned bulletCount = 0;
				while ( bulletCount < m_bulletAllowed )
				{
					unsigned randIndex = unsigned( rand() * BULLET_SLOT_COUNT );
					if ( !m_slot[ randIndex ] )
					{				
						m_slot[ randIndex ] = true;
						++bulletCount;
					}	
				}

				cout << "bullet layout " << m_slot << " " << m_curSlotIndex << endl;
				m_curSlotIndex = unsigned( rand() * BULLET_SLOT_COUNT );
				m_suviveCount = 0;

				//if ( hasEventListener( EVENT_RESET ) )
					//dispatchEvent( new Event( EVENT_RESET ) );
			}

			void tryShoot()
			{
				if ( m_slot[ m_curSlotIndex ] )
					_shot();
				else
				{
					_survive();

					m_curSlotIndex++;
					if ( m_curSlotIndex >= BULLET_SLOT_COUNT )
						m_curSlotIndex = 0;
				}
			}

		protected:
			void _shot()
			{
				onShot();
				//if ( hasEventListener( EVENT_SHOT ) )
					//dispatchEvent( new Event( EVENT_SHOT ) );
			}

			void _survive()
			{
				++m_suviveCount;
				onSurvive();
				//if ( hasEventListener( EVENT_SURVIVE ) )
					//dispatchEvent( new Event( EVENT_SURVIVE ) );
			}

			void onShot()
			{

			}

			void onSurvive()
			{

			}

			void onReset()
			{

			}

			static const std::wstring EVENT_SHOT = L"RR_shot";
			static const std::wstring EVENT_SURVIVE = L"RR_survive";
			static const std::wstring EVENT_RESET = L"RR_reset";

			static const unsigned BULLET_SLOT_COUNT= 6;
			static const unsigned DEFAULT_BULLET_COUNT = 1;

		private:
			unsigned m_bulletAllowed;
			bool m_slot[BULLET_SLOT_COUNT];
			unsigned m_curSlotIndex;
			unsigned m_suviveCount;
		};
	}
}