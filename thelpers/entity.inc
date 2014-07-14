
#if defined __thelpers_entity_included
	#endinput
#endif

#define __thelpers_entity_included


/**
 * Represents the base of the game entity hierarchy in the source engine
*/
methodmap CBaseEntity
{
	/**
	 * Create an instance of the CBaseEntity methodmap from an entity index
	 *
	 * @param entIndex		The entity index to bind this methodmap to. Can be an invalid entity index.
	 *						You can use the IsValid property to check if the given entity is valid or not.
	*/
	public CBaseEntity( int entIndex )
	{
		if ( !IsValidEntity( entIndex ) )
			return CBaseEntity:INVALID_ENT_REFERENCE;

		return CBaseEntity:EntIndexToEntRef( entIndex );
	}

	/**
	 * Gets the entity index of this entity instance.
	 * If the entity is invalid, INVALID_ENT_REFERENCE is returned instead.
	*/
	property int Index
	{
		public get() { return EntRefToEntIndex( _:this ); }
	}
	/**
	 * Gets the entity reference of this entity instance.
	*/
	property int Ref
	{
		public get() { return _:this; }
	}

	/**
	 * Gets a value indicating if this entity is valid or not.
	*/
	property bool IsValid
	{
		public get() { return IsValidEntity( this.Ref ); }
	}


	/**
	 * Returns an integer sendprop or datamap value.
	 *
	 * @param propType		The property type.
	 * @param propName		The name of the property to get.
	 * @param size			The size of the integer property. This parameter is only used if size detection fails.
	 * @param element		The element into the array to get, if this property is an array.
	*/
	public int GetProp( PropType propType, const char[] propName, int size = 4, int element = 0 )
	{
		return GetEntProp( this.Ref, propType, propName, size, element );
	}
	/**
	 * Returns a floating point sendprop or datamap value.
	 *
	 * @param propType		The property type.
	 * @param propName		The name of the property to get.
	 * @param element		The element into the array to get, if this property is an array.
	*/
	public float GetPropFloat( PropType propType, const char[] propName, int element = 0 )
	{
		return GetEntPropFloat( this.Ref, propType, propName, element );
	}
	/**
	 * Returns an entity sendprop or datamap value.
	 *
	 * @param propType		The property type.
	 * @param propName		The name of the property to get.
	 * @param element		The element into the array to get, if this property is an array.
	*/
	public CBaseEntity GetPropEnt( PropType propType, const char[] propName, int element = 0 )
	{
		int entIndex = GetEntPropEnt( this.Ref, propType, propName, element );
		return CBaseEntity( entIndex );
	}
	/**
	 * Returns a float vector sendprop or datamap value.
	 *
	 * @param propType		The property type.
	 * @param propName		The name of the property to get.
	 * @param vec			The vector buffer to store the value in.
	 * @param element		The element into the array to get, if this property is an array.
	*/
	public void GetPropVector( PropType propType, const char[] propName, float vec[ 3 ], int element = 0 )
	{
		GetEntPropVector( this.Ref, propType, propName, vec, element );
	}
	/**
	 * Returns a string sendprop or datamap value.
	 *
	 * @param propType		The property type.
	 * @param propName		The name of the property to get.
	 * @param buffer		The character buffer to store the value in.
	 * @param maxBuffer		The maximum size of the passed in character buffer.
	 * @param element		The element into the array to get, if this property is an array.
	 *
	 * @return	The number of non-null bytes written into the character buffer.
	*/
	public int GetPropString( PropType propType, const char[] propName, char[] buffer, int maxBuffer, int element = 0 )
	{
		return GetEntPropString( this.Ref, propType, propName, buffer, maxBuffer, element );
	}

	/**
	 * Sets an integer sendprop or datamap value.
	 *
	 * @param propType		The property type.
	 * @param propName		The name of the property to set.
	 * @param value			The value to set.
	 * @param size			The size of the integer property. This parameter is only used if size detection fails.
	 * @param element		The element into the array to set, if this property is an array.
	*/
	public void SetProp( PropType propType, const char[] propName, int value, int size = 4, int element = 0 )
	{
		SetEntProp( this.Ref, propType, propName, value, size, element );
	}
	/**
	 * Sets a floating point sendprop or datamap value.
	 *
	 * @param propType		The property type.
	 * @param propName		The name of the property to set.
	 * @param value			The value to set.
	 * @param element		The element into the array to set, if this property is an array.
	*/
	public void SetPropFloat( PropType propType, const char[] propName, float value, int element = 0 )
	{
		SetEntPropFloat( this.Ref, propType, propName, value, element );
	}
	/**
	 * Sets an entity sendprop or datamap value.
	 *
	 * @param propType		The property type.
	 * @param propName		The name of the property to set.
	 * @param value			The entity to set.
	 * @param element		The element into the array to set, if this property is an array.
	*/
	public void SetPropEnt( PropType propType, const char[] propName, CBaseEntity value, int element = 0 )
	{
		SetEntPropEnt( this.Ref, propType, propName, value.Ref, element );
	}
	/**
	 * Sets a float vector sendprop or datamap value.
	 *
	 * @param propType		The property type.
	 * @param propName		The name of the property to set.
	 * @param vec			The vector buffer value to set.
	 * @param element		The element into the array to set, if this property is an array.
	*/
	public void SetPropVector( PropType propType, const char[] propName, const float vec[ 3 ], int element = 0 )
	{
		SetEntPropVector( this.Ref, propType, propName, vec, element );
	}
	/**
	 * Sets a string sendprop or datamap value.
	 *
	 * @param propType		The property type.
	 * @param propName		The name of the property to get.
	 * @param buffer		The character buffer value to set.
	 *
	 * @return	The number of non-null bytes written into the sendprop or datamap.
	*/
	public int SetPropString( PropType propType, const char[] propName, const char[] buffer )
	{
		return SetEntPropString( this.Ref, propType, propName, buffer );
	}


	/**
	 * Gets the vector origin of the entity in local space (relative to the parent).
	 *
	 * @param vec		The vector buffer to store the entity origin in.
	*/
	public void GetLocalOrigin( float vec[ 3 ] )
	{
		this.GetPropVector( Prop_Send, "m_vecOrigin", vec );
	}
	/**
	 * Sets the vector origin of the entity in local space (relative to the parent).
	 *
	 * @param vec		The vector buffer to set the origin to.
	*/
	public void SetLocalOrigin( const float vec[ 3 ] )
	{
		this.SetPropVector( Prop_Send, "m_vecOrigin", vec );
	}
	/**
	 * Gets the vector angles of the entity in local space (relative to the parent).
	 *
	 * @param ang		The angle buffer to store the entity angles in.
	*/
	public void GetLocalAngles( float ang[ 3 ] )
	{
		this.GetPropVector( Prop_Send, "m_angRotation", ang );
	}
	/**
	 * Sets the vector angles of the entity in local space (relative to the parent).
	 *
	 * @param ang		The angle buffer to set the angles to.
	*/
	public void SetLocalAngles( const float ang[ 3 ] )
	{
		this.SetPropVector( Prop_Send, "m_angRotation", ang );
	}

	/**
	 * Gets the vector origin of the entity in world space.
	 *
	 * @param vec		The vector buffer to store the entity origin in.
	*/
	public void GetAbsOrigin( float vec[ 3 ] )
	{
		this.GetPropVector( Prop_Data, "m_vecAbsOrigin", vec );
	}
	/**
	 * Sets the vector origin of the entity in world space.
	 *
	 * @param vec		The vector buffer to set the origin to.
	*/
	public void SetAbsOrigin( const float vec[ 3 ] )
	{
		this.SetPropVector( Prop_Data, "m_vecAbsOrigin", vec );
	}
	/**
	 * Gets the vector angles of the entity in world space.
	 *
	 * @param ang		The angle buffer to store the entity angles in.
	*/
	public void GetAbsAngles( float ang[ 3 ] )
	{
		this.GetPropVector( Prop_Data, "m_angAbsRotation", ang );
	}
	/**
	 * Sets the vector angles of the entity in world space.
	 *
	 * @param ang		The angle buffer to set the angles to.
	*/
	public void SetAbsAngles( const float ang[ 3 ] )
	{
		this.SetPropVector( Prop_Data, "m_angAbsRotation", ang );
	}

	/**
	 * Spawns the entity into the game.
	 *
	 * @return		A boolean indicating if the entity was successfully spawned.
	*/
	public bool Spawn()
	{
		return DispatchSpawn( this.Ref );
	}

	/**
	 * Change an entity's origin, angles, or velocity instantly
	 *
	 * @param origin	New origin, or NULL_VECTOR for no change.
	 * @param angles	New angles, or NULL_VECTOR for no change.
	 * @param velocity	New velocity, or NULL_VECTOR for no change.
	*/
	public void Teleport( const float origin[ 3 ], const float angles[ 3 ], const float velocity[ 3 ] )
	{
		TeleportEntity( this.Ref, origin, angles, velocity );
	}

	/**
	 * Dispatch a Hammer entity key value into this entity.
	 *
	 * @param keyName		The key name of the keyvalue pair.
	 * @param value			The value of the keyvalue pair.
	 *
	 * @return		A boolean indicating if the entity has handled this key value.
	*/
	public bool KeyValue( const char[] keyName, const char[] value )
	{
		return DispatchKeyValue( this.Ref, keyName, value );
	}
	/**
	 * Dispatch a Hammer entity key value float into this entity.
	 *
	 * @param keyName		The key name of the keyvalue pair.
	 * @param value			The float value of the keyvalue pair.
	 *
	 * @return		A boolean indicating if the entity has handled this key value.
	*/
	public bool KeyValueFloat( const char[] keyName, float value )
	{
		return DispatchKeyValueFloat( this.Ref, keyName, value );
	}
	/**
	 * Dispatch a Hammer entity key value vector into this entity.
	 *
	 * @param keyName		The key name of the keyvalue pair.
	 * @param vec			The vector value of the keyvalue pair.
	 *
	 * @return		A boolean indicating if the entity has handled this key value.
	*/
	public bool KeyValueVector( const char[] keyName, const float vec[ 3 ] )
	{
		return DispatchKeyValueVector( this.Ref, keyName, vec );
	}

	/**
	 * Invokes a named entity input method on this entity. After completion, the global variant is re-initialized.
	 *
	 * @param input			The named input method to activate.
	 * @param activator		The entity which initiated the sequence of entity i/o, or INVALID_ENTITY for a NULL entity.
	 * @param caller		The entity from which this event was sent, or INVALID_ENTITY for a NULL entity.
	 * @param outputId		The unique ID of the output that this input was fired from.
	 *
	 * @return		A boolean value indicating if this input was successfully handled.
	*/
	public bool AcceptInput( const char[] input, CBaseEntity activator = CBaseEntity:INVALID_ENT_REFERENCE, CBaseEntity caller = CBaseEntity:INVALID_ENT_REFERENCE, int outputId = 0 )
	{
		return AcceptEntityInput( this.Ref, input, activator.Ref, caller.Ref, outputId );
	}

	/**
	 * Sets the move parent of this entity.
	 *
	 * @param parent		The entity to parent to.
	*/
	public void SetParent( CBaseEntity parent )
	{
		SetVariantString( "!activator" );
		this.AcceptInput( "SetParent", parent );
	}
	/**
	 * Sets the attachment point of the parent entity to use. This entity should already be parented before calling this.
	 * Can optionally also maintain the current position and angle offset from the parent entity.
	 *
	 * @param attachmentName		The name of the attachment to use.
	 * @param maintainOffset		A boolean value indicating if the current position and angle offsets should be maintained.
	*/
	public void SetParentAttachment( const char[] attachmentName, bool maintainOffset = false )
	{
		SetVariantString( attachmentName );

		if ( maintainOffset )
		{
			this.AcceptInput( "SetParentAttachmentMaintainOffset" );
		}
		else
		{
			this.AcceptInput( "SetParentAttachment" );
		}
	}

	/**
	 * Gets the move parent of this entity, if any.
	*/
	public CBaseEntity GetParent()
	{
		return this.GetPropEnt( Prop_Data, "m_pParent" );
	}
};


/**
 * A constant entity instance that represents an invalid entity.
*/
/*const*/ CBaseEntity INVALID_ENTITY = CBaseEntity:INVALID_ENT_REFERENCE;


/**
 * Helper function to create an entity and wrap it in a CBaseEntity methodmap.
*/
stock CBaseEntity Entity_CreateByName( const char[] className, int forceEdictIndex = -1 )
{
	int entIndex = CreateEntityByName( className, forceEdictIndex );
	return CBaseEntity( entIndex );
}

/**
 * Helper function to find an entity by classname and wrap the result in a CBaseEntity methodmap.
*/
stock CBaseEntity Entity_FindByClassname( CBaseEntity startEnt, const char[] className )
{
	int entIndex = FindEntityByClassname( startEnt.Ref, className );
	return CBaseEntity( entIndex );
}