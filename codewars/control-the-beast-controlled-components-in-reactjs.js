/*

In this kata you'll learn how to control Components with different kinds of beasts. Your goal is to tame and control a beast by building a controlled React component with the following criteria:

Create a component called Beast and its state name
The beast to control can be passed as a prop name
Render a textinput field with the id controlledName. Its value should be the name of the current beast.
Whenever this field's value is modified, the state should be updated as well
You should control the beast Yeti if name is not passed in
Read about controlled components here: https://reactjs.org/docs/forms.html#controlled-components

*/

const React = require('react');

class Beast extends React.Component {
	constructor(props) {
		super(props);
		this.state = { name: props.name !== undefined ? props.name : 'Yeti' };
	}

	setName(e) {
		this.setState({ name: e.target.value });
	}

	render() {
		return (
			<form>
				<textarea 
					id={'controlledName'}
					value={this.state.name}
					onChange={this.setName.bind(this)}
				/>
			</form>
		);
	}
}

