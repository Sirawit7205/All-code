Public Class Form5
    Private Sub Button3_Click(sender As System.Object, e As System.EventArgs) Handles Button3.Click
        Close()
        Form7.Close()
        Form6.Close()
        Form4.Show()
    End Sub

    Private Sub Form5_Load(sender As System.Object, e As System.EventArgs) Handles MyBase.Load
        TextBox1.Text = My.Settings.hint
        If My.Settings.correction(Form2.LevelIdent + Form4.quiz) = 1 Then
            TextBox2.Enabled = False
            Button2.Enabled = False
            Button4.Enabled = False
            TextBox2.Text = My.Settings.answers(Form2.LevelIdent + Form4.quiz)
            Label1.ForeColor = Color.Green
            Label1.Text = "Correct!"
            Label1.Visible = True
        End If
    End Sub

    Private Sub Button4_Click(sender As System.Object, e As System.EventArgs) Handles Button4.Click
        Form6.Show()
    End Sub

    Private Sub Button2_Click(sender As System.Object, e As System.EventArgs) Handles Button2.Click
        Dim ans As String
        'Dim loc As String
        ans = TextBox2.Text
        If ans.ToLower = My.Settings.answers(Form2.LevelIdent + Form4.quiz) Then
            TextBox2.Enabled = False
            Button2.Enabled = False
            Button4.Enabled = False
            Label1.ForeColor = Color.Green
            Label2.ForeColor = Color.Green
            Label1.Text = "Correct!"
            Label2.Text = My.Settings.scr_cur(Form2.LevelIdent + Form4.quiz) & " points"
            Label1.Visible = True
            Label2.Visible = True
            My.Settings.hint_plus += 1
            If (My.Settings.hint_plus = 5) Then
                My.Settings.hint_plus = 0
                My.Settings.hint += 1
                MessageBox.Show("Hint increased by 1!")
                TextBox1.Text = My.Settings.hint
            End If
            My.Settings.correct += 1
            My.Settings.correction(Form2.LevelIdent + Form4.quiz) = 1
            My.Settings.score += My.Settings.scr_cur(Form2.LevelIdent + Form4.quiz)
            'loc = "Form4.PictureBox" & 30 + Form4.quiz
            'Me.Controls(loc).Enabled = True
            If Form2.LevelIdent = 0 Then
                My.Settings.lv1 += 1
            ElseIf Form2.LevelIdent = 30 Then
                My.Settings.lv2 += 1
            ElseIf Form2.LevelIdent = 60 Then
                My.Settings.lv3 += 1
            ElseIf Form2.LevelIdent = 90 Then
                My.Settings.lv4 += 1
            Else
                My.Settings.lv5 += 1
            End If
        Else
            My.Settings.hint_plus = 0
            If My.Settings.scr_cur(Form2.LevelIdent + Form4.quiz) > 0 Then
                My.Settings.scr_cur(Form2.LevelIdent + Form4.quiz) -= 1
            End If
            Label1.ForeColor = Color.Red
            Label1.Text = "Incorrect!"
            Label1.Visible = True
        End If
    End Sub

    Private Sub Button1_Click(sender As System.Object, e As System.EventArgs) Handles Button1.Click
        Form7.Show()
    End Sub
End Class